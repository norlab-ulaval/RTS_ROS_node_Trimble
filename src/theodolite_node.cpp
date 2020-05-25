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

const int NUMBER_OF_SECONDS_STREAMING = 10;

/*int streamAndSaveImage(std::string filename, int streaming_time, SsiInstrument& instrument, int frame_to_save)
{
	VideoStreamingListener video_streaming_listener;
	instrument.Video(true, video_streaming_listener);
	
	while(video_streaming_listener.getCurrentImageCount() < 10 * streaming_time)
	{
		if(video_streaming_listener.getCurrentImageCount() == frame_to_save)
		{
			std::fstream image_file;
			image_file.open(filename, std::ios::out | std::ios::binary);

			if(image_file.is_open())
			{
				std::cout << "Image file openend" << std::endl;
				std::vector<char> current_image = video_streaming_listener.getImage();
				unsigned int current_image_size = current_image.size();
				image_file.write(current_image.data(), current_image_size);
				std::cout << "Wrote image to image file" << std::endl;
			}
			else
			{
				std::cout << "Problem in opening image file" << std::endl;
				return -1;
			}
			image_file.close();
			std::cout << "Image file closed" << std::endl;
		}
		sleep(0.1);
	}
	
	instrument.Video(false, video_streaming_listener);

	return 0;
}*/

int main(int argc, char **argv)
{
	// Set up ROS.
  ros::init(argc, argv, "theodolite_node");
  ros::NodeHandle n;
	
	SsiInstrument& instrument = SsiInstrument::GetInstrument();

	instrument.LoadDriver();

	std::cout << "Loaded driver" << std::endl;	
	std::cout << "Connecting..." << std::endl;

	int err = instrument.Connect();
	if(err)	{
		std::cout << "Error during connection: " << err << std::endl;
	}
	else{
		std::cout << "Intrument connected" << std::endl;
	}

	// ======================================
	
	instrument.Target(SsiInstrument::MODE_MULTITRACK, 1);
	std::shared_ptr<ObservationListener> observation_listener = std::make_shared<ObservationListener>();

	int number_of_measurements = 0;
	if(instrument.Tracking(true, observation_listener.get()) == 0)
	{
		std::cout << "Started measuring" << std::endl;
		number_of_measurements = observation_listener->getObservations()[0].size();
		std::cout << "Measuring...." << std::endl;
		int i = 0;
		while(number_of_measurements < 100 and i < 15)
		{
			std::cout << number_of_measurements << " measurements taken" << std::endl;
			number_of_measurements = observation_listener->getObservations()[0].size();
			i++;
			sleep(1);
		}
		std::cout << "Stopped measuring" << std::endl;
		instrument.Tracking(false, observation_listener.get());
	}
	else
	{
		std::cout << "Error in starting tracking" << std::endl;
	}

	observation_listener->saveFile("measurements.csv", 15);

	// ======================================

	std::cout << "Disconnecting..." << std::endl;

	instrument.FreeDriver();

	std::cout << "Unloaded driver" << std::endl;
	
	std::cout << "Terminating program" << std::endl;

	return 0;
}

int ssi_output(const char* fmt, ...)
{
	return 0;
}
