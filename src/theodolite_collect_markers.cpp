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

#define RECEIVE_TIMEOUT_MS 2000
#define TIME_BEFORE_NEXT_TX_ATTEMPT 10000
#define MAX_ATTEMPTS_BEFORE_SHUTDOWN 3

using namespace std;


// #############################################
// #############################################
//

//Option selected in launchfile
bool show_data = true;   //Option to see data on terminal when received
int rate = 10;           //Rate of listener in Hz
bool received_data = false;
bool received_dOk = false;
bool received_dNo = false;
bool received_nOk = false;
bool received_nNo = false;

byte status;
byte theodolite_number;
double elevation;
double azimuth;
double meas_distance;
uint32_t secs;
uint32_t nsecs;


struct TheodoliteMeasurement{
    byte theodolite_number;    
    byte status;    
    double azimuth;    
    double elevation;    
    double meas_distance;
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

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    
    received_data = false;
    received_dOk = false;
    received_dNo = false;
    received_nOk = false;
    received_nNo = false;


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
                                                                                   meas_distance,
                                                                                   secs,
                                                                                   nsecs) );                      

                        if(show_data && !corrupted_message)
                        {
                            ROS_INFO("Theodolite: %d ; HA: %f ; VA: %f ; Distance: %f ; Time server sec: %d ; Time server nsec: %d ; Status: %d \n", 
                               theodolite_number,
                               azimuth,
                               elevation,
                               meas_distance,
                               secs,
                               nsecs,
                               status);
                        }
                        else{
                            ROS_INFO("Not a coordinate messsage or malformed.");                        
                        }
                        received_data = true;
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
                        received_data = true;                   
                        break;
                    }
            
                    if(receivedbytes == 3)
                    {
                        if(message[0] == 'd'){
                            if(message[1] == 'O' && message[2] == 'k') {received_dOk = true; received_data = true; break;}
                            else if (message[1] == 'N' && message[2] == 'o') {received_dNo = true; received_data = true; break;}                            
                        }
    
                        if(message[0] == 'n'){
                            if(message[1] == 'O' && message[2] == 'k') {received_nOk = true; received_data = true; break;}
                            else if (message[1] == 'N' && message[2] == 'o') {received_nNo = true; received_data = true; break;}                            
                        }
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
               std::cout << "Waiting..." << std::endl;
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
    

    //general variables
    std::string tmp_string;
    enum State { INIT, SWITCH_THEODOLITES, WAIT_FOR_SWITCH_SUCCESS, COLLECT, WAIT_REPLY };
    enum TheodoliteState { UNKNOWN, DIRECT_MEASUREMENT, TRACKING };
    
    std::vector<std::vector<TheodoliteMeasurement>> markers_data_structure;
    std::vector<TheodoliteState> theodolite_states;
    std::vector<int> theodolite_attempts;

    int number_of_theodolites = 0;
    int number_of_markers = 0;
    int theodolite_currently_talked_to = 0;

    std::chrono::steady_clock::time_point time_waiting_start;
    
    State s = INIT;

    //Interactively get all the markers
    while (ros::ok())
    {
        switch(s)
        {
            case INIT:
                std::cout << "How many theodolites do we have? "; 
                std::getline(std::cin, tmp_string);
                try{
                    number_of_theodolites = stoi(tmp_string);
                }                
                catch (exception& e){
                    if(std::cin.eof()){
                        std::cout << std::endl << "EOF received, shutting down." << std::endl;
                        ros::shutdown();
                        continue;
                    }
                    std::cout << std::endl << "No no no, you have caused an exception in " << e.what() << ", c'mon..." << std::endl;
                    continue;
                }

                std::cout << "How many markers do we have? "; 
                std::getline(std::cin, tmp_string);
                try{
                    number_of_markers = stoi(tmp_string);
                }                
                catch (exception& e){
                    if(std::cin.eof()){
                        std::cout << std::endl << "EOF received, shutting down." << std::endl;
                        ros::shutdown();
                        continue;
                    }                    
                    std::cout << std::endl << "No no no, you have caused an exception in " << e.what() << ", c'mon..." << std::endl;
                    continue;
                }

                markers_data_structure = std::vector<std::vector<TheodoliteMeasurement>>(number_of_theodolites, std::vector<TheodoliteMeasurement>(number_of_markers));
                theodolite_states = std::vector<TheodoliteState>(number_of_theodolites, UNKNOWN);
                theodolite_attempts = std::vector<int>(number_of_theodolites, 0);
                
                std::cout << "Memory reserved for the coordinates." << std::endl;       
                s = SWITCH_THEODOLITES;
            break;

            case SWITCH_THEODOLITES:
    
                theodolite_currently_talked_to = 0;
        
                for (auto & theodolite_state : theodolite_states) {
                    if(theodolite_state == UNKNOWN) break;                    
                    else theodolite_currently_talked_to++;                                       
                }
                
                if(theodolite_currently_talked_to == number_of_theodolites){
                    std::cout << "All theodolites in Direct Mode, let's go to the next step." << std::endl; 
                    s = COLLECT;
                    continue;
                }else{    
                    std::cout << "Switching theodolite n." << theodolite_currently_talked_to+1 << " to Direct Mode." << std::endl;
                }
            
                Config_tx_mode();
                tmp_string = "d" + std::to_string(theodolite_currently_talked_to+1);
                txlora(tmp_string);
                Config_rx_mode();
                time_waiting_start = std::chrono::steady_clock::now();
                theodolite_attempts[theodolite_currently_talked_to] ++;
                std::cout << "Waiting for theodolite n." << theodolite_currently_talked_to+1 << " to reply." << std::endl;
                    
                s = WAIT_FOR_SWITCH_SUCCESS;
                
            break;

            case WAIT_FOR_SWITCH_SUCCESS:
                // Receive the message if there is one             
                Received_data_check();
                if(received_data){
                    if(received_dOk){
                        std::cout << "Success! Proceeding." << std::endl;
                        theodolite_states[theodolite_currently_talked_to] = DIRECT_MEASUREMENT;
                        s = SWITCH_THEODOLITES;
                        continue;
                    }
                    if(received_dNo){
                        std::cout << "Theodolite reported error! Shutting down." << std::endl;
                        ros::shutdown();
                        continue;
                    }
                else{
                        std::cout << "Received something, but not what we expected. Still waiting." << std::endl;
                        continue;
                    }
                }
                if(std::chrono::steady_clock::now() - time_waiting_start > std::chrono::milliseconds(TIME_BEFORE_NEXT_TX_ATTEMPT)){
                    std::cout << "Waiting for theodolite n." << theodolite_currently_talked_to+1 << " took longer than " << std::to_string(TIME_BEFORE_NEXT_TX_ATTEMPT/1000) << "s. ";
                    if(theodolite_attempts[theodolite_currently_talked_to] >= MAX_ATTEMPTS_BEFORE_SHUTDOWN){
                        std::cout << "Maximum number of attempts reached. Sorry, shutting down." << std::endl;
                        ros::shutdown();
                        continue;
                    }
                    std::cout << "Maybe packet lost. Will attempt again." << std::endl;
                    s = SWITCH_THEODOLITES;
                    continue;
                }
            break;
            
            case COLLECT:
                ros::shutdown();

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
                Received_data_check();
            
            break;
        }
        sleep(0.01);   
    }

    return 0;
}
