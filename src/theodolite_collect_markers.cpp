#include "ros/ros.h"

#include "theodolite_node_msgs/TheodoliteCoordsStamped.h"
#include "theodolite_node_msgs/TheodoliteTimeCorrection.h"

#include "lora_radio.h"
#include "radio_message_serialize.h"

#include <sstream>
#include <chrono>
#include <math.h>

//#include <mutex>
//#include <deque>
//#include <thread>
#include <iostream>
#include <condition_variable>
#include <chrono>

#define RECEIVE_TIMEOUT_MS 250

using namespace std;


// #############################################
// #############################################
//

//Option selected in launchfile
bool show_data = true;   //Option to see data on terminal when received
int rate = 10;           //Rate of listener in Hz
bool received_data = false;

struct TheodoliteMeasurement{
    byte theodolite_number;    
    byte status;    
    double azimuth;    
    double elevation;    
    double distance;
    uint32_t sec;
    uint32_t nsec;
};
     

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

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    received_data = false;
    while(received_data == false)
    {
        if(receivepacket(message, data_CRC_ok, show_data)){
            if(data_CRC_ok){
                
			    receivedbytes = message.size();

                if(receivedbytes >= 2)
                {
                    if(message[0]>0 && message[0]<10 )
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

                        if(show_data && !corrupted_message)
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
                        else{
                            ROS_INFO("Not a coordinate messsage or malformed.");                        
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
    //ROS init
    ros::init(argc, argv, "theodolite_collect_markers");
    ros::NodeHandle n("~");
    //Publisher of the data in a vector
    n.getParam("show_data", show_data);

    //Configure LoRa antenna
    General_setup_lora();
    Config_rx_mode();

    //general variables
    std::string tmp_string;
    enum State { INIT, COLLECT, WAIT_REPLY };
    std::vector<std::vector<TheodoliteMeasurement>> markers_data_structure;
    int number_of_theodolites = 0;
    int number_of_markers = 0;
    
    State s = INIT;

    //Interactively get all the markers
    while (ros::ok())
    {
        switch(s)
        {
            case INIT:
                std::cout << "How many theodolites do we have?"; 
                std::getline(std::cin, tmp_string);
                try{
                    number_of_theodolites = stoi(tmp_string);
                }                
                catch (exception& e){
                    std::cout << std::endl << "No no no, you have caused an exception in " << e.what() << ", c'mon..." << std::endl;
                    continue;
                }

                std::cout << "How many markers do we have?"; 
                std::getline(std::cin, tmp_string);
                try{
                    number_of_markers = stoi(tmp_string);
                }                
                catch (exception& e){
                    std::cout << std::endl << "No no no, you have caused an exception in " << e.what() << ", c'mon..." << std::endl;
                    continue;
                }
                
            break;
            
            case COLLECT:
            

            /*
            // Tx configuration to call theodolite targeted
            Config_tx_mode();
            txlora(toProcess.front());
            // Rx configuration to read the message send by the theodolite called
            Config_rx_mode();
            */
            
            break;
        
            case WAIT_REPLY:
                   
                // Received the message if there is one
                received_data = false;
                Received_data_check();
            
            break;
        }
        sleep(0.01);   
    }

    return 0;
}
