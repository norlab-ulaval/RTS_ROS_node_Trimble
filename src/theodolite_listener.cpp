#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64MultiArray.h"

#include "lora_radio.h"

#include <sstream>
#include <chrono>
#include <math.h>


using namespace std;


// #############################################
// #############################################
//

//Vector which will publish the data
std::vector<double> vec_data{0,0,0,0,0,0};
std::vector<ros::Duration> vec_correction{ros::Duration(0), ros::Duration(0), ros::Duration(0)};

//Option selected in launchfile
bool show_data = false;  //Option to see data on terminal when received
int rate = 10;           //Rate of listener in Hz
int number_of_theodolite = 1; //Number of theodolite used
bool received_data = false;
int number_first_synchronization = 50;
int delay_synchronization_theodolite = 300;
int delay_synchronization_between_theodolite = 10;
int number_others_synchronization = 5;

void Call_theodolite_selected(int number_theodolite, int param)
{
    std::string data;
    if(param == 0)
    {
        data = "t"+std::to_string(number_theodolite);
    }
    if(param == 1)
    {
        data = "p"+std::to_string(number_theodolite);
    }
    if(param == 2)
    {
        data = "e"+std::to_string(number_theodolite);
    }
    if(param == 3)
    {
        data = "s"+std::to_string(number_theodolite);
    }
    if(param == 4)
    {
        data = "c"+std::to_string(number_theodolite);
    }
    unsigned char *send_message = new unsigned char[data.length()+1];
    strcpy((char *)send_message,data.c_str());
    txlora(send_message, strlen((char *)send_message));
    delete send_message;
}

void Update_number_theodolite_called(int &number_theodolite, int max_theodolite_number)
{
    number_theodolite++;
    if(number_theodolite > max_theodolite_number)
    {
        number_theodolite=1;
    }
}

void Read_data(std::string &message_string, bool &corrupted_message, bool &received_data, std::vector<double> &vec_data, int &iterator_vector)
{
    std::string single_word_string;

    // looking for the theodolite data and split message
    size_t delimiter_position = message_string.find(';');
    if(delimiter_position == std::string::npos){
        received_data = true;
        corrupted_message=true;
    }

    if(!corrupted_message)
    {
        single_word_string = message_string.substr(0, delimiter_position);
        message_string = message_string.substr(delimiter_position+1, std::string::npos);

        try{
            vec_data[iterator_vector] = stod(single_word_string); 
            iterator_vector++;  
        }
        catch (const std::invalid_argument & ia){
            ROS_WARN((std::string("Invalid theodolite message received!")+ia.what()).c_str());
            received_data = true;
            corrupted_message=true;                    
        }
    }
}

void Read_data_Synchronization(std::string &message_string, bool &corrupted_message, bool &received_data, ros::Time &time, int param)
{
    std::string single_word_string;

    // looking for the theodolite id number
    size_t delimiter_position = message_string.find(';');
    if(delimiter_position == std::string::npos){
        received_data = false;
        corrupted_message=true;
    }

    if(!corrupted_message)
    {
        //std::cout << "String : " <<  message_string << "\n";
        single_word_string = message_string.substr(0, delimiter_position);
        message_string = message_string.substr(delimiter_position+1, std::string::npos);
        //std::cout << "String conversion : " <<  single_word_string << "\n";
        try{
            if(param == 1)
            {   
                time.sec = stoul(single_word_string);
            }
            if(param == 2)
            {   
                time.nsec = stoul(single_word_string);
            }
        }
        catch (const std::invalid_argument & ia){
            ROS_WARN((std::string("Invalid theodolite id received!")+ia.what()).c_str());
            received_data = false;
            corrupted_message=true;                    
        }
    }
}

void Received_data_check(ros::Publisher data_pub, int number_theodolite_called)
{
    std::vector<byte> message;
    std::string message_string;
    unsigned int receivedbytes;
    bool data_CRC_ok = false;
    bool corrupted_message = false;
    int iterator_vector = 0;

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    received_data = false;
    while(received_data == false)
    {
        if(receivepacket(message, data_CRC_ok, show_data)){
            if(data_CRC_ok){
                // Copy the bytes into a string
			    receivedbytes = message.size();
                for(int i=0; i < receivedbytes; i++){
                    message_string.push_back(message[i]);
                } 

                if(receivedbytes >= 2)
                {
                    if(message[0]!='p')
                    {
                        // looking for the theodolite data
                        
                        Read_data(message_string, corrupted_message, received_data, vec_data, iterator_vector);
                        Read_data(message_string, corrupted_message, received_data, vec_data, iterator_vector);
                        Read_data(message_string, corrupted_message, received_data, vec_data, iterator_vector);
                        Read_data(message_string, corrupted_message, received_data, vec_data, iterator_vector);
                        Read_data(message_string, corrupted_message, received_data, vec_data, iterator_vector);
                        Read_data(message_string, corrupted_message, received_data, vec_data, iterator_vector);

                        //vec_data[4] = timestamp_message.sec;
                        //vec_data[5] = timestamp_message.nsec;

                        ros::Time timestamp_message;
                        timestamp_message.sec = vec_data[4];
                        timestamp_message.nsec = vec_data[5];

                        timestamp_message = timestamp_message - vec_correction[number_theodolite_called-1];

                        vec_data[4] = timestamp_message.sec;
                        vec_data[5] = timestamp_message.nsec;
                        
                        std_msgs::Float64MultiArray msg;
                        msg.layout.dim.push_back(std_msgs::MultiArrayDimension());
                        msg.layout.dim[0].size = 6;
                        msg.layout.dim[0].stride =1;

                        vector<double>::const_iterator itr, end(vec_data.end());
                        for(itr = vec_data.begin(); itr!=end; ++itr) {
                           msg.data.push_back(*itr);
                        }

                        if(show_data)
                        {
                            ROS_INFO("theodolite: %f ; HA: %f ; VA: %f ; Distance: %f ; Time server sec: %f ; Time server nsec: %f \n", vec_data[0], vec_data[1], vec_data[2], vec_data[3], vec_data[4], vec_data[5]);
                        }
                        data_pub.publish(msg);        
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
            if(std::chrono::steady_clock::now() - start > std::chrono::milliseconds(200))
            {
               received_data = false;
               ROS_WARN("200 milisec timeout");
               break;
            }
        }
        
    }
    
}

void Received_data_Synchronization(list<ros::Time> &list_data)
{
    std::vector<byte> message;
    std::string message_string;
    unsigned int receivedbytes;
    bool data_CRC_ok = false;
    bool corrupted_message = false;

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    received_data = false;
    while(received_data == false)
    {
        if(receivepacket(message, data_CRC_ok, show_data)){
            if(data_CRC_ok){
                // Copy the bytes into a string
			    receivedbytes = message.size();
                for(int i=0; i < receivedbytes; i++){
                    message_string.push_back(message[i]);
                } 

                if(receivedbytes >= 2)
                {
                    if(message[0]=='e')
                    {
                        received_data = true;
                    }    
                    if(message[0]=='s')
                    {
                        received_data = true;
                        ros::Time new_time;
                        Read_data_Synchronization(message_string, corrupted_message, received_data, new_time,0);
                        if(!corrupted_message && received_data)
                        {
                            Read_data_Synchronization(message_string, corrupted_message, received_data, new_time,1);
                            if(!corrupted_message && received_data)
                            {
                                Read_data_Synchronization(message_string, corrupted_message, received_data, new_time,2);
                                if(!corrupted_message && received_data)
                                {
                                    list_data.push_back(new_time);
                                }
                            }
                        } 
                    }
                    if(corrupted_message)
                    {
                        ROS_WARN("Received corrupted message (bad CRC) !");
                        corrupted_message=true;  
                        received_data = false; 
                        break;    
                    }
                }
            }
            else{
                    ROS_WARN("Received corrupted message (bad CRC) !");
                    corrupted_message=true;  
                    received_data = false; 
                    break;    
            }
            break;
        }
        else{
            delay(1);
            if(std::chrono::steady_clock::now() - start > std::chrono::milliseconds(200))
            {
               received_data = false;
               ROS_WARN("200 milisec timeout");
               break;
            }
        }
        
    }
    
}

void Synchronization_call(int number_of_ping, int number_theodolite_pinged, ros::Publisher correction_pub, int param)
{
    ros::Time begin_time;
    ros::Time end_time;

    list<ros::Time> time_begin_server, time_received_theodolite, time_received_server, average_server;
    list<double> duration_theodolite_server;

    //Send message to theodolite to ask a synchronise mode
    Config_tx_mode();
    Call_theodolite_selected(number_theodolite_pinged, 1);
   
    //Loop to have Delta t
    for(int j=0; j<number_of_ping; j++)
    {
        //Save time begin
        begin_time = ros::Time::now();
        //Send message to theodolite
        Config_tx_mode();
        Call_theodolite_selected(number_theodolite_pinged, 2);
        //Received message from theodolite
        Config_rx_mode();
        Received_data_Synchronization(time_received_theodolite);
        if(received_data)
        {
            //Save time 
            end_time = ros::Time::now();
            //Ask time of theodolite
            Config_tx_mode();
            Call_theodolite_selected(number_theodolite_pinged, 3);
            //Receive time of theodolite
            Config_rx_mode();
            Received_data_Synchronization(time_received_theodolite);
            if(received_data)
            {
                time_begin_server.push_back(begin_time);
                time_received_server.push_back(end_time);
            }
        }
    }  

    //send message to theodolite to close synchronize mode
    Config_tx_mode();
    Call_theodolite_selected(number_theodolite_pinged, 4);

    if( ((time_received_theodolite.size() == time_begin_server.size()) || (time_received_server.size() == time_begin_server.size())) && time_received_theodolite.size()>0 && time_begin_server.size()>0 && time_received_server.size()>0 )
    {
        std::list<ros::Time>::iterator it_bs = time_begin_server.begin();
        std::list<ros::Time>::iterator it_rs = time_received_server.begin();
        for (int i=0;i<time_begin_server.size();i++)
        {     
            average_server.push_back(*it_bs + (*it_rs - *it_bs)*0.5);
            std::advance(it_bs, 1);
            std::advance(it_rs, 1);
        }

        std::list<ros::Time>::iterator it_as = average_server.begin();
        std::list<ros::Time>::iterator it_rt = time_received_theodolite.begin();
        for (int i=0;i<average_server.size();i++)
        {     
            ros::Duration duration_ts = *it_rt - *it_as; 
            duration_theodolite_server.push_back(duration_ts.toSec());
            std::advance(it_as, 1);
            std::advance(it_rt, 1);
        }

        double avg = 0;
        double var = 0;
        std::list<double>::iterator it;
        for(it = duration_theodolite_server.begin(); it != duration_theodolite_server.end(); it++) avg += *it;
        avg /= duration_theodolite_server.size();

        for(it = duration_theodolite_server.begin(); it != duration_theodolite_server.end(); it++) var += pow(*it-avg,2);
        var /= duration_theodolite_server.size();

        ROS_INFO("Number of ping analyzed: %i", duration_theodolite_server.size());
        ROS_INFO("Average value (s): %0.9f", avg);
        ROS_INFO("Standard value (s): %0.9f", pow(var, 0.5));

        //Update correction
        if(param ==1 && vec_correction[number_theodolite_pinged-1].toSec()!=0)
        {
            vec_correction[number_theodolite_pinged-1] = ros::Duration(avg*0.1) + ros::Duration(vec_correction[number_theodolite_pinged-1].toSec()*0.9);
        }
        else
        {
            vec_correction[number_theodolite_pinged-1] = ros::Duration(avg);
        }

        std_msgs::Float64MultiArray msg;
        msg.layout.dim.push_back(std_msgs::MultiArrayDimension());
        msg.layout.dim[0].size = 4;
        msg.layout.dim[0].stride =1;

        ros::Time timestamp = ros::Time::now();
        msg.data.push_back(timestamp.sec);
        msg.data.push_back(timestamp.nsec);
        msg.data.push_back((double) number_theodolite_pinged);
        msg.data.push_back(vec_correction[number_theodolite_pinged-1].toSec());

        correction_pub.publish(msg);        
        
    }
    else
    {
        ROS_WARN("Synchronization failed! Bad number of data.");
    }
    
}


// #############################################
// #############################################
// Main program

int main(int argc, char **argv)
{
    //ROS init
    ros::init(argc, argv, "theodolite_listener");
    ros::NodeHandle n;
    //Publisher of the data in a vector
    ros::Publisher data_pub = n.advertise<std_msgs::Float64MultiArray>("theodolite_data", 10);
    ros::Publisher correction_pub = n.advertise<std_msgs::Float64MultiArray>("theodolite_correction_timestamp", 10);
    n.getParam("/theodolite_listener/rate", rate);
    //Set the rate of the listener
    if(rate >100 or rate<1)
    {
        printf("Error in rate setting! Should be between 1 and 100Hz. Defaut rate of 30Hz is applying! \n");
        rate = 30;
    }
    ros::Rate loop_rate(rate);
    //Get number of theodolite involved
    n.getParam("/theodolite_listener/number_of_theodolite", number_of_theodolite);
    n.getParam("/theodolite_listener/show_data", show_data);
    n.getParam("/theodolite_listener/number_first_synchronization", number_first_synchronization);
    n.getParam("/theodolite_listener/number_others_synchronization", number_others_synchronization);
    n.getParam("/theodolite_listener/delay_synchronization_theodolite", delay_synchronization_theodolite);
    n.getParam("/theodolite_listener/delay_synchronization_between_theodolite", delay_synchronization_between_theodolite);

    //Configure LoRa antenna
    General_setup_lora();

    printf("------------------\n");

    //Iterator to call theodolite
    int number_theodolite_called=1;
    int max_theodolite_number = number_of_theodolite;

    //Main synchronization for theodolites
    ROS_INFO("Begin synchronization of time for all theodolites !");
    delay(100);

    for(int i=0;i<max_theodolite_number;i++)
    {
        Synchronization_call(number_first_synchronization, i+1, correction_pub, 0);
    }
    ROS_INFO("End synchronization of time !");

    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
    bool start_others_synchronization = false;
    int iterator_synchronization = 0;

    ROS_INFO("Start calling theodolites.");

    //Listen messages sent
    while (ros::ok())
    {
        //Check if synchronization nedded
        if(start_others_synchronization == false)
        {
            if(std::chrono::steady_clock::now() - start_time > std::chrono::seconds(delay_synchronization_theodolite))
            {
                start_others_synchronization = true;
                ROS_INFO("Begin synchronization for theodolite %i", iterator_synchronization+1);
                Synchronization_call(number_others_synchronization, iterator_synchronization+1, correction_pub, 1);
                ROS_INFO("End synchronization for theodolite %i", iterator_synchronization+1);
                iterator_synchronization++;
                start_time = std::chrono::steady_clock::now();
                if(max_theodolite_number == 1)
                {
                    iterator_synchronization = 0;
                    start_others_synchronization = false;
                } 
            }
        }
        if(start_others_synchronization == true)
        {
            if(std::chrono::steady_clock::now() - start_time > std::chrono::seconds(delay_synchronization_between_theodolite))
            {
                ROS_INFO("Begin synchronization for theodolite %i", iterator_synchronization+1);
                Synchronization_call(number_others_synchronization, iterator_synchronization+1, correction_pub, 1);
                ROS_INFO("End synchronization for theodolite %i", iterator_synchronization+1);
                iterator_synchronization++;
                start_time = std::chrono::steady_clock::now();
                if(max_theodolite_number == iterator_synchronization)
                {
                    iterator_synchronization = 0;
                    start_others_synchronization = false;
                }   
            }
        }

        // Tx configuration to call theodolite targeted
        Config_tx_mode();
        // Send message to all theodolite, and by the same time call the one we want
        Call_theodolite_selected(number_theodolite_called,0);
        // Rx configuration to read the message send by the theodolite called
        Config_rx_mode();
       
        // Received the message if there is one
        received_data = false;
        Received_data_check(data_pub, number_theodolite_called);

        // Update the theodolite called for later
        Update_number_theodolite_called(number_theodolite_called, max_theodolite_number);

        // Delay to let time for the theodolite to switch mode
        delay(10);

        // Update ros loop        
        ros::spinOnce();

    }

    return 0;
}
