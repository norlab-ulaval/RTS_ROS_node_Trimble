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


void Call_theodolite_selected(int number_theodolite)
{
    std::string data = "t"+std::to_string(number_theodolite);
    unsigned char *send_message = new unsigned char[data.length()+1];
    strcpy((char *)send_message,data.c_str());
    printf("%i \n", number_theodolite);
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

void Received_data_check(ros::NodeHandle n, ros::Publisher data_pub)
{
    std::vector<byte> message;
    std::string message_string;
    std::string single_word_string;
    unsigned int receivedbytes;
    bool data_CRC_ok = false;
    bool corrupted_message = false;

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    while(received_data == false)
    {
        if(receivepacket(message, data_CRC_ok, show_data)){
            if(data_CRC_ok){
                // Copy the bytes into a string
			    receivedbytes = message.size();
                for(int i=0; i < receivedbytes; i++){
                    message_string.push_back(message[i]);
                }
                
                std::cout << "String: " << message_string << std::endl;  

                if(receivedbytes >= 2)
                {
                    // looking for the theodolite id number
                    size_t delimiter_position = message_string.find(';');
                    if(delimiter_position == std::string::npos){
                        received_data = true;
                        corrupted_message=true;
                        break;
                    }
                    single_word_string = message_string.substr(0, delimiter_position);
                    message_string = message_string.substr(delimiter_position+1, std::string::npos);

                    std::cout << "Word: " << single_word_string << std::endl;
                    std::cout << "Rest: " << message_string << std::endl;

                    try{
                        vec_data[0] = (double) stoi(single_word_string);    
                    }
                    catch (const std::invalid_argument & ia){
                        ROS_WARN((std::string("Invalid theodolite id received!")+ia.what()).c_str());
                        received_data = true;
                        corrupted_message=true;
                        break;                    
                    }
  
                    std::cout << "Data [0]: " << vec_data[0] << std::endl;
                                           
                    /*
                    ...

                    //Obtain horizontal angle
                    int new_iterator = 2;
                    int old_iterator = 2;
                    while(message[new_iterator]!=';' or new_iterator<(int)receivedbytes)
                    {
                        new_iterator+=1;
                    }
                    if(new_iterator >= (int)receivedbytes)
                    {
                      corrupted_message=true;
                    }
                    char* HA_char = new char[new_iterator-old_iterator];
                    for(int i=0; i<new_iterator-old_iterator; i++)
                    {
                        HA_char[i]= (char)message[i+old_iterator];
                    }
                    vec_data[1] = atof(HA_char);

                    //Obtain vertical angle
                    new_iterator += 1;
                    old_iterator = new_iterator;
                    while(message[new_iterator]!=';' or new_iterator<(int)receivedbytes)
                    {
                        new_iterator+=1;
                    }
                    if(new_iterator >= (int)receivedbytes)
                    {
                        corrupted_message=true;
                    }
                    char* VA_char = new char[new_iterator-old_iterator];
                    for(int i=0; i<new_iterator-old_iterator; i++)
                    {
                        VA_char[i]= (char)message[i+old_iterator];
                    }
                    vec_data[2] = atof(VA_char);

                    //Obtain distance
                    new_iterator += 1;
                    old_iterator = new_iterator;
                    while(message[new_iterator]!=';' or new_iterator<(int)receivedbytes)
                    {
                       new_iterator+=1;
                    }
                    if(new_iterator >= (int)receivedbytes)
                    {
                       corrupted_message=true;
                    }
                    char* dist_char = new char[new_iterator-old_iterator];
                    for(int i=0; i<new_iterator-old_iterator; i++)
                    {
                       dist_char[i]= (char)message[i+old_iterator];
                    }
                    vec_data[3] = atof(dist_char);

                    //Obtain time of data
                    new_iterator += 1;
                    old_iterator = new_iterator;
                    while(message[new_iterator]!=';' or new_iterator<(int)receivedbytes)
                    {
                       new_iterator+=1;
                    }
                    if(new_iterator >= (int)receivedbytes)
                    {
                       corrupted_message=true;
                    }
                    char* time_char = new char[new_iterator-old_iterator];
                    for(int i=0; i<new_iterator-old_iterator; i++)
                    {
                       time_char[i]= (char)message[i+old_iterator];
                    }
                       vec_data[4] = atof(time_char);


                    std_msgs::Float64MultiArray msg;
                    msg.layout.dim.push_back(std_msgs::MultiArrayDimension());
                    msg.layout.dim[0].size = 7;
                    msg.layout.dim[0].stride =1;

                    vector<double>::const_iterator itr, end(vec_data.end());
                    for(itr = vec_data.begin(); itr!=end; ++itr) {
                       msg.data.push_back(*itr);
                    }

                    if(show_data)
                    {
                       ROS_INFO("theodolite: %f \n HA: %f \n VA: %f \n Distance: %f \n Time: %f \n", vec_data[0], vec_data[1], vec_data[2], vec_data[3], vec_data[4]);
                    }

                    data_pub.publish(msg);           */           
                }
                received_data = true;
            }
            else{
                    ROS_WARN("Received corrupted message (bad CRC)");
                    received_data = true;
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

    // Delay parameter in milliseconds between each message sent
    int time_delay = 30;

    //Listen messages sent
    while (ros::ok())
    {
        // Tx configuration to call theodolite targeted
        Config_tx_mode();

        //printf("------------------\n");

        // Send message to all theodolite, and by the same time call the one we want
        Call_theodolite_selected(number_theodolite_called);

        // Rx configuration to read the message send by the theodolite called
        Config_rx_mode();
        
        // Update the theodolite called for later
        Update_number_theodolite_called(number_theodolite_called, max_theodolite_number);

        // Delay to let time for the theodolite to switch mode
        delay(time_delay);

        //printf("------------------\n");

        // Received the message if there is one
        received_data = false;
        Received_data_check(n, data_pub);

        // Update ros loop        
        ros::spinOnce();

    }

    return 0;
}
