#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64MultiArray.h"

#include "lora_radio.h"

#include <sstream>
#include <chrono>


using namespace std;


// #############################################
// #############################################
//

//Vector which will publish the data
std::vector<double> vec_data{0,0,0,0,0};

//Option selected in launchfile
bool show_data = false;  //Option to see data on terminal when received
int rate = 10;           //Rate of listener in Hz
int number_of_theodolite = 1; //Number of theodolite used
bool received_data = false;


void Call_theodolite_selected(int number_theodolite, int param)
{
    if(param == 0)
    {
        std::string data = "t"+std::to_string(number_theodolite);
        unsigned char *send_message = new unsigned char[data.length()+1];
        strcpy((char *)send_message,data.c_str());
        printf("%i \n", number_theodolite);
        txlora(send_message, strlen((char *)send_message));
        delete send_message;
    }
    if(param == 1)
    {
        std::string data = "p"+std::to_string(number_theodolite);
        unsigned char *send_message = new unsigned char[data.length()+1];
        strcpy((char *)send_message,data.c_str());
        txlora(send_message, strlen((char *)send_message));
        delete send_message;
    }
    if(param == 2)
    {
        std::string data = "e"+std::to_string(number_theodolite);
        unsigned char *send_message = new unsigned char[data.length()+1];
        strcpy((char *)send_message,data.c_str());
        txlora(send_message, strlen((char *)send_message));
        delete send_message;
    }
    if(param == 3)
    {
        std::string data = "s"+std::to_string(number_theodolite);
        unsigned char *send_message = new unsigned char[data.length()+1];
        strcpy((char *)send_message,data.c_str());
        txlora(send_message, strlen((char *)send_message));
        delete send_message;
    }
    if(param == 4)
    {
        std::string data = "c"+std::to_string(number_theodolite);
        unsigned char *send_message = new unsigned char[data.length()+1];
        strcpy((char *)send_message,data.c_str());
        txlora(send_message, strlen((char *)send_message));
        delete send_message;
    }
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

    // looking for the theodolite id number
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
            vec_data[iterator_vector] = (double) stof(single_word_string);  
            iterator_vector++;  
        }
        catch (const std::invalid_argument & ia){
            ROS_WARN((std::string("Invalid theodolite id received!")+ia.what()).c_str());
            received_data = true;
            corrupted_message=true;                    
        }
    }
}

void Read_data_Synchronization(std::string &message_string, bool &corrupted_message, bool &received_data, list<float> &list_data)
{
    std::string single_word_string;

    // looking for the theodolite id number
    size_t delimiter_position = message_string.find(';');
    if(delimiter_position == std::string::npos){
        received_data = true;
        corrupted_message=true;
    }

    if(!corrupted_message)
    {
        single_word_string = message_string.substr(delimiter_position+1, std::string::npos-1);

        std::cout << "String : " <<  message_string << "\n";
        std::cout << "String conversion : " <<  single_word_string << "\n";

        try{
            list_data.push_back(stof(single_word_string)); 
            printf("Float conversion: %f \n", stof(single_word_string));
            
        }
        catch (const std::invalid_argument & ia){
            ROS_WARN((std::string("Invalid theodolite id received!")+ia.what()).c_str());
            received_data = true;
            corrupted_message=true;                    
        }
    }
}

void Received_data_check(ros::NodeHandle n, ros::Publisher data_pub)
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
      
                        std_msgs::Float64MultiArray msg;
                        msg.layout.dim.push_back(std_msgs::MultiArrayDimension());
                        msg.layout.dim[0].size = 5;
                        msg.layout.dim[0].stride =1;

                        vector<double>::const_iterator itr, end(vec_data.end());
                        for(itr = vec_data.begin(); itr!=end; ++itr) {
                           msg.data.push_back(*itr);
                        }

                        if(show_data)
                        {
                           ROS_INFO("theodolite: %f ; HA: %f ; VA: %f ; Distance: %f ; Time: %f \n", vec_data[0], vec_data[1], vec_data[2], vec_data[3], vec_data[4]);
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
            if(std::chrono::steady_clock::now() - start > std::chrono::milliseconds(100))
            {
               received_data = false;
               ROS_WARN("100 milisec timeout");
               break;
            }
        }
        
    }
    
}

void Received_data_Synchronization(list<float> &list_data)
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
                        Read_data_Synchronization(message_string, corrupted_message, received_data, list_data);
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
            if(std::chrono::steady_clock::now() - start > std::chrono::milliseconds(100))
            {
               received_data = false;
               ROS_WARN("100 milisec timeout");
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
    ros::init(argc, argv, "theodolite_listener");
    ros::NodeHandle n;
    //Publisher of the data in a vector
    ros::Publisher data_pub = n.advertise<std_msgs::Float64MultiArray>("theodolite_data", 10);
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

    //Configure LoRa antenna
    General_setup_lora();


    printf("------------------\n");

    //Iterator to call theodolite
    int number_theodolite_called=1;
    int max_theodolite_number = number_of_theodolite;

    printf("Begin synchronization of time");
    //Synchronisation bloc
    for(int i=0; i<max_theodolite_number; i++)
    {
        list<float> time_begin_server, time_received_theodolite, time_received_server;

        //Send message to theodolite to ask a synchronise mode
        Config_tx_mode();
        Call_theodolite_selected(number_theodolite_called,1);
       
        //Loop to have Delta t
        for(int j=0; j<50; j++)
        {
            //Save time 
            time_begin_server.push_back(ros::Time::now().toSec());
            //Send message to theodolite
            Config_tx_mode();
            Call_theodolite_selected(number_theodolite_called,2);
            //Received message from theodolite
            Config_rx_mode();
            Received_data_Synchronization(time_received_theodolite);
            //Save time 
            time_received_server.push_back(ros::Time::now().toSec());
            //Ask time of theodolite
            Config_tx_mode();
            Call_theodolite_selected(number_theodolite_called,3);
            //Receive time of theodolite
            Config_rx_mode();
            Received_data_Synchronization(time_received_theodolite);
        }  

        //send message to theodolite to close synchronize mode
        Config_tx_mode();
        Call_theodolite_selected(number_theodolite_called,4);
 
    }

    printf("End synchronization of time");

    //Listen messages sent
    while (ros::ok())
    {
        // Tx configuration to call theodolite targeted
        Config_tx_mode();
        // Send message to all theodolite, and by the same time call the one we want
        Call_theodolite_selected(number_theodolite_called,0);
        // Rx configuration to read the message send by the theodolite called
        Config_rx_mode();
       
        // Update the theodolite called for later
        Update_number_theodolite_called(number_theodolite_called, max_theodolite_number);
        // Received the message if there is one
        received_data = false;
        Received_data_check(n, data_pub);

        // Delay to let time for the theodolite to switch mode
        delay(10);

        // Update ros loop        
        ros::spinOnce();

    }

    return 0;
}
