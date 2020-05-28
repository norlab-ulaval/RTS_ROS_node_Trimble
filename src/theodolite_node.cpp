#include "ros/ros.h"
#include "std_msgs/String.h"

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

extern int ssi_output(const char* fmt, ...);

int main(int argc, char **argv)
{
	// Set up ROS.
    ros::init(argc, argv, "theodolite_node");
    ros::NodeHandle n;

    while(ros::ok())
    {
        //Get parameters
        //Number of target prism
        int target_prism = 0;
        n.getParam("/theodolite_node/target_prism", target_prism); 
        //Number of measurements decided   
        int number_of_measurements_choice = 10;
        n.getParam("/theodolite_node/number_of_measurments", number_of_measurements_choice);                
        
        if(target_prism > 8 or target_prism < 1){
		    std::cout << "Wrong target prism number! Change the value to begin." << std::endl;
            return 0;
	    }
        else{
            if(number_of_measurements_choice < 0){
		        std::cout << "Wrong number of measurements! Change the value to begin." << std::endl;
                return 0;
	        }
	        else{
                std::cout << "Target prism acquired is: " << target_prism << std::endl;
                std::cout << "Number of measurements decided is: " << number_of_measurements_choice << std::endl;
                
                //Load driver of the theodolite
                SsiInstrument& instrument = SsiInstrument::GetInstrument();
                instrument.LoadDriver();

	            std::cout << "Loaded driver" << std::endl;	
	            std::cout << "Connecting..." << std::endl;

                //Connect to the theodolite
	            int err = instrument.Connect();
	            if(err)	{
		            std::cout << "Error during connection: " << err << std::endl;
                    
                    //Disconnect driver of theodolite
                    instrument.FreeDriver();

	                std::cout << "Unloaded driver" << std::endl;
	                std::cout << "Terminating program" << std::endl;
	                return 0;
	            }
	            else{
		            std::cout << "Intrument connected" << std::endl;
	            
                    //Select Multitrack mode with the proper prism number
                    instrument.Target(SsiInstrument::MODE_MULTITRACK, target_prism);
	                std::shared_ptr<ObservationListener> observation_listener = std::make_shared<ObservationListener>();

                    //Begin tracking of prism
                    if(instrument.Tracking(true, observation_listener.get()) == 0)
	                {
                        //Variable to detect new measurments
                        int number_of_measurements_new = 0;   //New number of measurments
                        int number_of_measurements_old = 0;   //Old number of measurments
                        
		                std::cout << "Started measuring" << std::endl;

                        if(number_of_measurements_choice == 0)  //Case we want not stop measurements
                        {
                            while(true)
	                        {
                                try{
                                    usleep(30);  //Time to wait a new measurement (frequency of measurements is around 2.5Hz)
                                    number_of_measurements_new = observation_listener->getSizeVector();     //Get number of measurements stored
                                    if(number_of_measurements_new > number_of_measurements_old)         //If a new one is detected
                                    {
                                        //Print data of measurement
		                                std::cout << number_of_measurements_new << " measurements taken" << std::endl;
                                        number_of_measurements_old = number_of_measurements_new;
                                        std::cout << "HORIZONTAL_ANGLE_VECTOR: " << (observation_listener->getObservations())[0][number_of_measurements_new-1] << std::endl;
                                        std::cout << "VERTICAL_ANGLE_VECTOR: " << (observation_listener->getObservations())[1][number_of_measurements_new-1] << std::endl;
                                        std::cout << "DISTANCE_VECTOR: " << (observation_listener->getObservations())[2][number_of_measurements_new-1] << std::endl;
                                        std::cout << "TIMESTAMP_VECTOR: " << (observation_listener->getObservations())[3][number_of_measurements_new-1] << std::endl;
                                        std::cout << "ERROR: " << (observation_listener->getObservations())[4][number_of_measurements_new-1] << std::endl;
                                    }
                                }
                                catch(std::exception& e)
	                            {
		                            printf("%s\n", e.what());
	                            }
                            }
                        }
                        else
                        {
	                        while(number_of_measurements_new <= number_of_measurements_choice)      //Case we want a limited number of measurements
	                        {
                                try{
                                    usleep(30);  //Time to wait a new measurement (frequency of measurements is around 2.5Hz)
                                    number_of_measurements_new = observation_listener->getSizeVector();     //Get number of measurements stored
                                    if(number_of_measurements_new > number_of_measurements_old)         //If a new one is detected
                                    {
                                        //Print data of measurement
		                                std::cout << number_of_measurements_new << " measurements taken" << std::endl;
                                        number_of_measurements_old = number_of_measurements_new;
                                        std::cout << "HORIZONTAL_ANGLE_VECTOR: " << (observation_listener->getObservations())[0][number_of_measurements_new-1] << std::endl;
                                        std::cout << "VERTICAL_ANGLE_VECTOR: " << (observation_listener->getObservations())[1][number_of_measurements_new-1] << std::endl;
                                        std::cout << "DISTANCE_VECTOR: " << (observation_listener->getObservations())[2][number_of_measurements_new-1] << std::endl;
                                        std::cout << "TIMESTAMP_VECTOR: " << (observation_listener->getObservations())[3][number_of_measurements_new-1] << std::endl;
                                        std::cout << "ERROR: " << (observation_listener->getObservations())[4][number_of_measurements_new-1] << std::endl;
                                    }
                                }
                                catch(std::exception& e)
	                            {
		                            printf("%s\n", e.what());
	                            }
	                        }
                        }
                        //Stop measurement when it's finished
	                    std::cout << "Stopped measuring" << std::endl;
	                    instrument.Tracking(false, observation_listener.get());

                        bool save_measurements = false;
                        n.getParam("/theodolite_node/save_measurements", save_measurements); 
                        if(save_measurements)
                        {
                            std::string file_measurements;
                            n.getParam("/theodolite_node/file_measurements", file_measurements);
                            std::cout << "Save measurements in " << file_measurements << std::endl;
                            observation_listener->saveFile(file_measurements, 10);
                        }
	                }
	                else
	                {
		                std::cout << "Error in starting tracking" << std::endl;
	                }

                    //Disconnect of the theodolite and remove driver
                    std::cout << "Disconnecting..." << std::endl;
	                instrument.FreeDriver();
	                std::cout << "Unloaded driver" << std::endl;
	                std::cout << "Terminating program" << std::endl;
	                return 0;

                }
            }
	    }
    }
}

int ssi_output(const char* fmt, ...)
{
	return 0;
}
