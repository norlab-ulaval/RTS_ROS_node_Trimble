#include "ros/ros.h"

#include "theodolite_node_msgs/TheodoliteCoordsStamped.h"
#include "theodolite_node_msgs/TheodoliteTimeCorrection.h"

#include "lora_radio.h"
#include "radio_message_serialize.h"

#include <sstream>
#include <chrono>
#include <math.h>

#include <mutex>
#include <deque>
#include <thread>
#include <iostream>
#include <condition_variable>
#include <chrono>

#define RECEIVE_TIMEOUT_MS 250

using namespace std;


// #############################################
// #############################################
//

//Option selected in launchfile
bool show_data = false;  //Option to see data on terminal when received
int rate = 10;           //Rate of listener in Hz
bool received_data = false;

void Received_data_check()
{
    std::vector<byte> message;
    unsigned int receivedbytes;
    bool data_CRC_ok = false;
    bool corrupted_message = false;
    int iterator_vector = 0;

    byte status;
    byte theodolite_number;
    double elevation;
    double azimuth;
    double distance;
    uint32_t secs;
    uint32_t nsecs;

    double corrected_secs;
    double corrected_nsecs;

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    received_data = false;
    while(received_data == false)
    {
        if(receivepacket(message, data_CRC_ok, show_data)){
            if(data_CRC_ok){
                
			    receivedbytes = message.size();

                if(receivedbytes >= 2)
                {
                    if(message[0]!='p')
                    {
                        // looking for the theodolite data
                        corrupted_message = !( unpack_theodolite_message_from_bytes(message,
                                                                                   theodolite_number,
                                                                                   status,
                                                                                   elevation,
                                                                                   azimuth,
                                                                                   distance,
                                                                                   secs,
                                                                                   nsecs) );                      

                        if(show_data)
                        {
                            ROS_INFO("Theodolite: %d ; HA: %f ; VA: %f ; Distance: %f ; Time server sec: %d ; Time server nsec: %d ; Status: %d \n", 
                               theodolite_number,
                               azimuth,
                               elevation,
                               distance,
                               secs,
                               nsecs,
                               status);
                        }
                        break;
                    }
                       
                    if(message[0]=='s')
                    {
                        received_data = true;
                        uint32_t secs, nsecs;
                        byte command_code;
                        
                        corrupted_message = !( unpack_theodolite_time_from_bytes(message,
                                                                                 command_code,
                                                                                 secs,
                                                                                 nsecs));
                        if(!corrupted_message){
                            ROS_INFO("Theodolite responded this time: sec: %d; nsec: %d\n", 
                               secs,
                               nsecs);                                             
                        }                        
                        break;
                    }
                }
            }
            else{
                ROS_WARN("Received corrupted message (bad CRC)");
                corrupted_message=true;       
            }
            break;
        }
        else{
            delay(1);
            if(std::chrono::steady_clock::now() - start > std::chrono::milliseconds(RECEIVE_TIMEOUT_MS))
            {
               received_data = false;
               ROS_WARN("Receive timeout when waiting for theodolite response.");
               break;
            }
        }
        
    }
    
}




// #############################################
// #############################################
// Main program

int main(int argc, char **argv)
{   
    std::condition_variable cv;
    std::mutex mutex;
    std::deque<std::string> lines; // protected by m    

    //ROS init
    ros::init(argc, argv, "theodolite_interactive_master");
    ros::NodeHandle n;
    //Publisher of the data in a vector
    n.getParam("/theodolite_listener/show_data", show_data);

    //Configure LoRa antenna
    General_setup_lora();

    printf("------------------\n");
    ROS_INFO("Spinning up a thread for io.");
    
    // thread to read from stdin
    std::thread io{[&]{
        std::string tmp;
        while (true) {
            std::getline(std::cin, tmp);
            std::lock_guard<std::mutex> lock(mutex);
            lines.push_back(std::move(tmp));
            cv.notify_one();
        }
    }};
    ROS_INFO("Type messages and send by ENTER. Now you are the master!");

    //Listen messages sent
    std::deque<std::string> toProcess;
    while (ros::ok())
    {
        {
            // critical section
            std::unique_lock<std::mutex> lock(mutex);
            if (cv.wait_for(lock, std::chrono::seconds(0), [&]{ return !lines.empty(); })) {
                // get a new batch of lines to process
                std::swap(lines, toProcess);
            }
        }

        if (!toProcess.empty()) {
            std::cout << "Sending the message..." << std::endl;
            // Tx configuration to call theodolite targeted
            Config_tx_mode();
            txlora(toProcess.front());
            // Rx configuration to read the message send by the theodolite called
            Config_rx_mode();
            toProcess.clear();
        }
        
       
        // Received the message if there is one
        received_data = false;
        Received_data_check();

        sleep(0.01);   
    }

    return 0;
}
