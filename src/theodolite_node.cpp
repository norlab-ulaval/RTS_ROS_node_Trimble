//For ros
#include "ros/ros.h"
#include "std_msgs/String.h"

#include "lora_radio.h"

#include <sstream>
#include <chrono>


//For theodolite
#include "SsiCommand.h"
#include "SsiInstrument.h"
#include "VideoStreamingListener.h"
#include "ObservationListener.h"

#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <array>
#include <fstream>
#include <iostream>
#include <vector>
#define ASIO_STANDALONE
#include <asio/thread_pool.hpp>
#include <asio/post.hpp>

// Data of theodolite
double HA;          //Horizontal angle
double VA;          //Vertical angle
double Dist;        //Distance
double Time_sec;        //Time sec
double Time_nsec;        //Time nsec
int error_theodolite;   //flag for error
int theodolite_number = 0;
bool received_data = false;
bool break_iterator = false;
bool show_data = false;
bool synchronization_mode = false;
ros::Time time_saved;

void Received_data_check()
{
    std::vector<byte> message;
    std::string message_string;
    std::string data;

    unsigned int receivedbytes;
    bool data_CRC_ok = false;
    bool corrupted_message = false;

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    
    received_data = false;
    while(received_data == false)
    {
        if(receivepacket(message, data_CRC_ok, show_data)){
            if(data_CRC_ok){
                corrupted_message = false;
                // Copy the bytes into a string
			    receivedbytes = message.size();
                for(int i=0; i < receivedbytes; i++){
                    message_string.push_back(message[i]);
                }

                if(receivedbytes >= 2)
                {
                    if(message[0]=='t' && message[1]==('0' + theodolite_number))
                    {
                        received_data = true;
                    } 
                    if(message[0]=='p' && message[1]==('0' + theodolite_number))
                    {
                        received_data = true;
                        synchronization_mode = true;
                    }
                    if(message[0]=='e' && message[1]==('0' + theodolite_number))
                    {
                        time_saved = ros::Time::now();
        
                        //printf("time_Ex: %d.%d \n", time_Ex.sec,time_Ex.nsec);

                        received_data = true;
                        Config_tx_mode();		    
                        data = "e"+std::to_string(theodolite_number)+";";
                        unsigned char *send_message = new unsigned char[data.length()+1];
                        strcpy((char *)send_message, data.c_str());
                        txlora(send_message, strlen((char *)send_message));
                        delete send_message;
                        
                    }
                    if(message[0]=='s' && message[1]==('0' + theodolite_number))
                    {
                        received_data = true;
                        Config_tx_mode();
                        data = "s;" + std::to_string(time_saved.sec) + ";" + std::to_string(time_saved.nsec) + ";";
                        unsigned char *send_message = new unsigned char[data.length()+1];
                        strcpy((char *)send_message, data.c_str());
                        txlora(send_message, strlen((char *)send_message));
                        delete send_message;
                    }
                    if(message[0]=='c' && message[1]==('0' + theodolite_number))
                    {
                        received_data = true;
                        synchronization_mode = false;
                    }
                       
                }
            }
            else{
                    ROS_WARN("Received corrupted message (bad CRC)");
                    corrupted_message=true;   
                    received_data = false;   
            }
            break;
        }
        else
        {
            delay(1);
            if(std::chrono::steady_clock::now() - start > std::chrono::milliseconds(1000))
            {
                received_data = false;
                ROS_WARN("1000 milisec timeout");
                break;
            }
        }
        
    }
    
}

void Synchronization_mode()
{
    while(synchronization_mode == true)
    {
        Config_rx_mode();
	    Received_data_check();
    }
    Config_rx_mode();
	Received_data_check();
}

void Check_new_observation(std::shared_ptr<ObservationListener> observation_listener, int number_of_measurements_new, int number_of_measurements_old)
{
    number_of_measurements_new = observation_listener->getSizeVector();     //Get number of measurements stored
	if(number_of_measurements_new > number_of_measurements_old)         //If a new one is detected
	{
		HA = (observation_listener->getObservations())[0][number_of_measurements_new-1];
		VA = (observation_listener->getObservations())[1][number_of_measurements_new-1];
		Dist = (observation_listener->getObservations())[2][number_of_measurements_new-1];
		Time_sec = (observation_listener->getObservations())[3][number_of_measurements_new-1];
        Time_nsec = (observation_listener->getObservations())[4][number_of_measurements_new-1];
		error_theodolite = (observation_listener->getObservations())[5][number_of_measurements_new-1];
		number_of_measurements_old = number_of_measurements_new;

		if(show_data)
		{
			//Print data of measurement
            ROS_INFO("%i  measurements taken", number_of_measurements_new);
            ROS_INFO("HORIZONTAL_ANGLE_VECTOR: %f", HA);
            ROS_INFO("VERTICAL_ANGLE_VECTOR: %f", VA);
            ROS_INFO("DISTANCE_VECTOR: %f", Dist);
            ROS_INFO("TIMESTAMPSEC_VECTOR: %f", Time_sec);
            ROS_INFO("TIMESTAMPNSEC_VECTOR: %f", Time_nsec);
            ROS_INFO("ERROR: %i", error_theodolite);
		}
	}
}

void Lora_communication(int theodolite_number, double HA, double VA, double Dist, double time_sec, double time_nsec)
{
    Config_rx_mode();
	Received_data_check();
	Config_tx_mode();

    if(received_data)
    {

        if(synchronization_mode)
        {
            ROS_INFO("Synchronization asked!");
            Synchronization_mode();
            ROS_INFO("End of synchronization!");
        }

        //Send data to robot
        std::string data = std::to_string(theodolite_number) + ";" + std::to_string(HA) + ";" + std::to_string(VA) + ";" + std::to_string(Dist) + ";";
        unsigned char *send_message = new unsigned char[data.length()+1];
        strcpy((char *)send_message,data.c_str());
        txlora(send_message, strlen((char *)send_message));
        delete send_message;

     	delay(5);
    }
}

//Fonction for theodolite
extern int ssi_output(const char* fmt, ...);

/////******************************************************************////////////
/////******************************************************************////////////
/////******************************************************************////////////

int main(int argc, char **argv)
{
	// Set up ROS.
    ros::init(argc, argv, "theodolite_node");
    ros::NodeHandle n;

    //while(ros::ok())
    {
        //Get parameters
        //Theodolite number (to differentiate data if many theodolites target one prism)
        n.getParam("/theodolite_node/theodolite_number", theodolite_number);
        //Number of target prism
        int target_prism = 0;
        n.getParam("/theodolite_node/target_prism", target_prism); 
        //Number of measurements decided   
        int number_of_measurements_choice = 10;
        n.getParam("/theodolite_node/number_of_measurments", number_of_measurements_choice);    
        bool use_lora = false;
        n.getParam("/theodolite_node/use_lora", use_lora);
        n.getParam("/theodolite_node/show_data", show_data);
        bool test_lora = false;
        n.getParam("/theodolite_node/test_lora", test_lora);
        int test_rate = 10;
        n.getParam("/theodolite_node/test_rate", test_rate);
        ros::Rate loop_rate(test_rate);
    
        printf("\n");

        //Initialize the connection with LoRa antenna if needed
        if(use_lora or test_lora)
        {
            ROS_INFO("Starting LoRa antenna");

            General_setup_lora();
        }

		// If no test with fake data
		if(!test_lora)
        {       
        
			if(theodolite_number < 1 or theodolite_number > 8)
			{
                ROS_WARN("Error in setting of theodolite number! Number should be between 1 and 8.");
            	break_iterator = true;
			}

			if(target_prism > 8 or target_prism < 1)
			{
                ROS_WARN("Wrong target prism number! Change the value to begin. Should be between 1 and 8.");
            	break_iterator = true;
			}

			if(number_of_measurements_choice < 0)
			{
                ROS_WARN("Wrong number of measurements! Change the value to begin. Should be 0 or higher.");
				break_iterator = true;
			}

            ROS_INFO("Target prism acquired is: %i", target_prism);
			if(number_of_measurements_choice != 0)
                ROS_INFO("Number of measurements decided is: %i", number_of_measurements_choice);
			else
                ROS_INFO("Number of measurements decided is infinite !");
                      
			//Load driver of the theodolite
			SsiInstrument& instrument = SsiInstrument::GetInstrument();
			instrument.LoadDriver();

            ROS_INFO("Loaded driver");
            ROS_INFO("Connecting...");

			//Connect to the theodolite
			int err = instrument.Connect();
			if(err)	
			{
                ROS_WARN("Error during connection!");
				std::cout << err << std::endl;
                          
				//Disconnect driver of theodolite
				instrument.FreeDriver();

                ROS_INFO("Unloaded driver");
                ROS_INFO("Terminating program");
	            break_iterator = true;
			}

			if(break_iterator == false)
			{

                ROS_INFO("Intrument connected");
			              
				//Select Multitrack mode with the proper prism number
				instrument.Target(SsiInstrument::MODE_MULTITRACK, target_prism);
				std::shared_ptr<ObservationListener> observation_listener = std::make_shared<ObservationListener>();

				//Begin tracking of prism
				if(instrument.Tracking(true, observation_listener.get()) == 0)
				{
					//Variable to detect new measurments
					int number_of_measurements_new = 0;   //New number of measurments
					int number_of_measurements_old = 0;   //Old number of measurments
		                          
                    ROS_INFO("Started measuring");

					if(number_of_measurements_choice == 0)  //Case we want not stop measurements
					{
						while(ros::ok())
						{
							try
							{                       
								Check_new_observation(observation_listener, number_of_measurements_new, number_of_measurements_old);

                                if(use_lora)
								{
									Lora_communication(theodolite_number, HA, VA, Dist, Time_sec, Time_nsec);
								}
								else
								{
									usleep(50);  //Time to wait a new measurement (frequency of measurements is around 2.5Hz)
								}    
                                
							}
							catch(std::exception& e)
							{
								ROS_WARN("%s\n", e.what());
							}
						}
					}
					else
					{
						while(number_of_measurements_new <= number_of_measurements_choice)      //Case we want a limited number of measurements
						{
							try
							{
								Check_new_observation(observation_listener, number_of_measurements_new, number_of_measurements_old);

                                if(use_lora)
								{
									Lora_communication(theodolite_number, HA, VA, Dist, Time_sec, Time_nsec);
								}
								else
								{
									usleep(50);  //Time to wait a new measurement (frequency of measurements is around 2.5Hz)
								}    
							}
							catch(std::exception& e)
							{
                                ROS_WARN("%s\n", e.what());
							}
						}
					}
					//Stop measurement when it's finished
                    ROS_INFO("Stopped measuring");
					instrument.Tracking(false, observation_listener.get());

					//Save data in file if asked
					bool save_measurements = false;
					n.getParam("/theodolite_node/save_measurements", save_measurements); 
					if(save_measurements)
					{
						std::string file_measurements;
						n.getParam("/theodolite_node/file_measurements", file_measurements);
                        ROS_INFO("Save measurements in %s", file_measurements.c_str());
						observation_listener->saveFile(file_measurements, 10);
					}
				}
				else
				{
                    ROS_WARN("Error in starting tracking");
				}
				
			}

            //Disconnect of the theodolite and remove driver
            ROS_INFO("Disconnecting...");
	        instrument.FreeDriver();
            ROS_INFO("Unloaded driver");
            ROS_INFO("Terminating program");
		}
		else
		{
			while(ros::ok())
			{
                Lora_communication(1, 2.14578, 5.58749, 6.14785, 1598131342.0, 388808162.0);

                delay(5);
		     	
                ros::spinOnce();
		    }
		}

    

    }
    
	return 0;
}

int ssi_output(const char* fmt, ...)
{
	return 0;
}
