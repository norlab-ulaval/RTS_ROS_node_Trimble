#include "ros/ros.h"

#include "theodolite_node_msgs/TheodoliteCoordsStamped.h"
#include "theodolite_node_msgs/TheodoliteTimeCorrection.h"

#include "lora_radio.h"
#include "radio_message_serialize.h"

#include <sstream>
#include <fstream>
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
bool received_measurement = false;

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

    TheodoliteMeasurement():theodolite_number(0), status(255), azimuth(0.0), elevation(0.0), meas_distance(0.0), sec(0), nsec(0){};
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
    received_measurement = false;


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

                        if(!corrupted_message){
                            received_data = true;
                            received_measurement = true;
                        }else{
                            received_data = true;
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


void print_marker_table(std::vector<std::vector<TheodoliteMeasurement>> markers_data_structure){
    int number_of_theodolites = markers_data_structure.size();
    if(!number_of_theodolites) return;
    int number_of_markers = markers_data_structure[0].size();
    if(!number_of_markers) return;

    std::cout << std::endl << "Markers collected so far: (X == not yet, ▓ == collected)" << std::endl ;
    std::cout << "Theodolite:\t| " ;
    for(int i = 0; i < number_of_theodolites; i++){
        std::cout << i+1 << "\t| " ;        
    }
    std::cout << std::endl;

    for(int i = 0; i < number_of_markers; i++){
        std::cout << "Marker " << i+1 << ":\t| ";
        for(int j = 0; j < number_of_theodolites; j++){
            std::cout << (markers_data_structure[j][i].status==255 ? "X" : "▓") << "\t| ";        
        }
        std::cout << std::endl;
    }
}


// #############################################
// #############################################
// Main program

int main(int argc, char **argv)
{   
    //ROS init
    ros::init(argc, argv, "theodolite_collect_calib_prisms");
    ros::NodeHandle n("~");
    //Publisher of the data in a vector
    n.getParam("show_data", show_data);

    //Configure LoRa antenna
    General_setup_lora();
    
    //general variables
    std::string tmp_string;
    enum State { INIT, SWITCH_THEODOLITES, WAIT_FOR_SWITCH_SUCCESS, COLLECT, WAIT_REPLY, SAVE, SWITCH_TO_TRACKING, WAIT_FOR_SWITCH2_SUCCESS, QUIT};
    enum TheodoliteState { UNKNOWN, DIRECT_MEASUREMENT, TRACKING };
    
    std::vector<std::vector<TheodoliteMeasurement>> markers_data_structure;
    std::vector<TheodoliteState> theodolite_states;
    std::vector<int> theodolite_attempts;

    int number_of_theodolites = 0;
    int number_of_markers = 0;
    int theodolite_currently_talked_to = 0;
    int marker_currently_waited_for = 0;

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

                if(number_of_theodolites < 1 || number_of_markers < 1){
                    std::cout << std::endl << "Zero or minus number of theodolites or markers. C'mon... " << std::endl;
                    continue;
                }                

                markers_data_structure = std::vector<std::vector<TheodoliteMeasurement>>(number_of_theodolites, std::vector<TheodoliteMeasurement>(number_of_markers));
                theodolite_states = std::vector<TheodoliteState>(number_of_theodolites, UNKNOWN);
                theodolite_attempts = std::vector<int>(number_of_theodolites, 0);
                
                std::cout << "Memory reserved for the coordinates." << std::endl;
                print_marker_table(markers_data_structure);
                std::cout << std::endl;
                                       
                s = SWITCH_THEODOLITES;
                //s = COLLECT;
            break;

            case SWITCH_THEODOLITES:
    
                theodolite_currently_talked_to = 0;
        
                for (auto & theodolite_state : theodolite_states) {
                    if(theodolite_state == UNKNOWN) break;                    
                    else theodolite_currently_talked_to++;                                       
                }
                
                if(theodolite_currently_talked_to == number_of_theodolites){
                    std::cout << "All theodolites in Direct Mode, let's go to the next step." << std::endl;
                    theodolite_currently_talked_to = 0; 
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
                print_marker_table(markers_data_structure);
                std::cout << "To choose a theodolite: t[x]. To request a mesurement: m[x]. To exit CTRL+D. Currently selected theodolite n." << theodolite_currently_talked_to+1 << std::endl;
                std::cout << "Input: ";
                
                std::getline(std::cin, tmp_string);
                if(std::cin.eof()){
                        std::cout << std::endl << "EOF received, saving and shutting down." << std::endl;
                        s = SAVE;                        
                        continue;
                }
                if(tmp_string.length() < 2) continue;
                if(tmp_string[0]=='t'){
                
                    try{
                        theodolite_currently_talked_to = stoi(tmp_string.substr(1, std::string::npos)) - 1;
                    }                
                    catch (exception& e){
                        std::cout << std::endl << "Invalid input." << std::endl;
                        continue;
                    }
                    if(theodolite_currently_talked_to < 0 || theodolite_currently_talked_to >= number_of_theodolites){
                        std::cout << "Invalid theodolite number." << std::endl;
                        theodolite_currently_talked_to = 0;
                    }

                    continue;
                }

                if(tmp_string[0]=='m'){
                
                    try{
                        marker_currently_waited_for = stoi(tmp_string.substr(1, std::string::npos)) - 1;
                    }                
                    catch (exception& e){
                        std::cout << std::endl << "Invalid input." << std::endl;
                        continue;
                    }
                    if(marker_currently_waited_for < 0 || marker_currently_waited_for >= number_of_markers){
                        std::cout << "Invalid marker number." << std::endl;
                        continue;
                        
                    }
                    std::cout << "Requesting measurement of the marker " << marker_currently_waited_for+1 
                        << " from theodolite " << theodolite_currently_talked_to << std::endl;
                    
                    Config_tx_mode();
                    tmp_string = "t" + std::to_string(theodolite_currently_talked_to+1);
                    txlora(tmp_string);
                    Config_rx_mode();
                    time_waiting_start = std::chrono::steady_clock::now();
                    std::cout << "Waiting for theodolite n." << theodolite_currently_talked_to+1 << " to reply with the measurement." << std::endl;
                    s = WAIT_REPLY;
                    continue;
                }
                        
                continue;
            break;
        
            case WAIT_REPLY:
                   
                // Received the message if there is one
                Received_data_check();
                if(received_data){
                    if(received_measurement){
                        if(status!=0){
                            std::cout << "The theodolite responded with a non-zero status: " << (int)status << "which means an error. Check it." << std::endl;
                        }
                        else{
                            std::cout << "Success! Storing the data." << std::endl;
                            markers_data_structure[theodolite_currently_talked_to][marker_currently_waited_for].status = status;
                            markers_data_structure[theodolite_currently_talked_to][marker_currently_waited_for].theodolite_number = theodolite_number;
                            markers_data_structure[theodolite_currently_talked_to][marker_currently_waited_for].elevation = elevation;
                            markers_data_structure[theodolite_currently_talked_to][marker_currently_waited_for].azimuth = azimuth;
                            markers_data_structure[theodolite_currently_talked_to][marker_currently_waited_for].meas_distance = meas_distance;
                            markers_data_structure[theodolite_currently_talked_to][marker_currently_waited_for].sec = secs;
                            markers_data_structure[theodolite_currently_talked_to][marker_currently_waited_for].nsec = nsecs;
                        }                        
                        s = COLLECT;
                        continue;
                    }
                    else{
                        std::cout << "Received something, but not what we expected. Still waiting." << std::endl;
                        continue;
                    }
                }
                if(std::chrono::steady_clock::now() - time_waiting_start > std::chrono::milliseconds(TIME_BEFORE_NEXT_TX_ATTEMPT)){
                    std::cout << "Waiting for theodolite n." << theodolite_currently_talked_to+1 << " took longer than " << std::to_string(TIME_BEFORE_NEXT_TX_ATTEMPT/1000) << "s. ";
                    std::cout << "Maybe packet lost. Try again." << std::endl;
                    s = COLLECT;
                    continue;
                }
            
            break;

            case SAVE:
                {
                    ofstream output_file;
                    output_file.open("theodolite_reference_markers.txt", ios::out | ios::trunc);
                    output_file << "theodolite_number , marker_number , status , elevation , azimuth , distance , sec , nsec" << std::endl;
                    for(int i = 0; i < number_of_theodolites; i++){
                        for(int j = 0; j < number_of_markers; j++){
                            output_file << i+1 << " , " << j+1 
                                << " , " << (int)markers_data_structure[i][j].status 
                                << " , " << markers_data_structure[i][j].elevation
                                << " , " << markers_data_structure[i][j].azimuth
                                << " , " << markers_data_structure[i][j].meas_distance
                                << " , " << markers_data_structure[i][j].sec
                                << " , " << markers_data_structure[i][j].nsec << std::endl;         
                        }
                    }
                    output_file.close();
                }
                theodolite_attempts = std::vector<int>(number_of_theodolites, 0);
                s = SWITCH_TO_TRACKING;
                continue;
            break;

            case SWITCH_TO_TRACKING:
                theodolite_currently_talked_to = 0;
        
                for (auto & theodolite_state : theodolite_states) {
                    if(theodolite_state == DIRECT_MEASUREMENT) break;                    
                    else theodolite_currently_talked_to++;                                       
                }
                
                if(theodolite_currently_talked_to == number_of_theodolites){
                    std::cout << "All theodolites back in Tracking Mode or to be switched manually, we are done." << std::endl;
                    theodolite_currently_talked_to = 0; 
                    s = QUIT;
                    continue;
                }else{    
                    std::cout << "Switching theodolite n." << theodolite_currently_talked_to+1 << " to Tracking Mode." << std::endl;
                }
            
                Config_tx_mode();
                tmp_string = "n" + std::to_string(theodolite_currently_talked_to+1);
                txlora(tmp_string);
                Config_rx_mode();
                time_waiting_start = std::chrono::steady_clock::now();
                theodolite_attempts[theodolite_currently_talked_to] ++;
                std::cout << "Waiting for theodolite n." << theodolite_currently_talked_to+1 << " to reply." << std::endl;
                    
                s = WAIT_FOR_SWITCH2_SUCCESS;

            break;

            case WAIT_FOR_SWITCH2_SUCCESS:
                // Receive the message if there is one             
                Received_data_check();
                if(received_data){
                    if(received_nOk){
                        std::cout << "Success! Proceeding." << std::endl;
                        theodolite_states[theodolite_currently_talked_to] = TRACKING;
                        s = SWITCH_TO_TRACKING;
                        continue;
                    }
                    if(received_nNo){
                        std::cout << "Theodolite " << theodolite_currently_talked_to << " reported error while switching to the tracking mode! Restart it manually." << std::endl;
                        theodolite_states[theodolite_currently_talked_to] = UNKNOWN;
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
                        std::cout << "Maximum number of attempts to switch theo. " << theodolite_currently_talked_to+1 << " reached.. Do it manually." << std::endl;
                        theodolite_states[theodolite_currently_talked_to] = UNKNOWN;
                        continue;
                    }
                    std::cout << "Maybe packet lost. Will attempt again." << std::endl;
                    s = SWITCH_TO_TRACKING;
                    continue;
                }
                
            break;

            case QUIT:
                ros::shutdown();
                continue;
            break;
        }
        sleep(0.01);   
    }

    return 0;
}
