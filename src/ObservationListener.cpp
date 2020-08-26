#include "ObservationListener.h"

#include "Observations/IAngleObservation.h"
#include "Observations/IDistanceObservation.h"
#include "Observations/ITimeObservation.h"

#include <vector>
#include <iostream>
#include <fstream>
#include "ros/ros.h"

ObservationListener::ObservationListener()
{
    observations = std::vector<std::vector<double>>(6, std::vector<double>());
    size_vector=0;
}

ObservationListener::~ObservationListener()
{
}

void ObservationListener::observationTracked(const SSI::TrackingObservationsEvent& event)
{   
    std::cout << "new observation event" << std::endl;
    double horizontal_angle = 0;
    double vertical_angle = 0;
    double distance = 0;
	double timestamp_sec = 0;
    double timestamp_nsec = 0;
    int error = 0;

    try
    {
        SSI::TSObservationContainer container = event.getObservationContainer();

        std::vector<SSI::ITSObservation*> obs = container.getObservations();
        for(std::vector<SSI::ITSObservation*>::iterator it = obs.begin(); it != obs.end(); it++)
        {
            if((*it)->getObservationType() == SSI::OT_AngleObservation)
            {
                SSI::IAngleObservation* angle_observation = (SSI::IAngleObservation*)(*it);
                horizontal_angle = angle_observation->getAngles().getHorizontalAngle();
                vertical_angle = angle_observation->getAngles().getVerticalAngle();
                //std::cout << "HA: " << horizontal_angle << "VA: " << vertical_angle << std::endl;
            }
            else if((*it)->getObservationType() == SSI::OT_DistanceObservation)
            {
                SSI::IDistanceObservation* distance_observation = (SSI::IDistanceObservation*)(*it);
                distance = distance_observation->getSlopeDistance();
                //std::cout << "Dist: " << distance <<  std::endl;
            }
			else if ((*it)->getObservationType() == SSI::OT_TimeObservation)
			{
				SSI::ITimeObservation* time = (SSI::ITimeObservation*)(*it);
                //timestamp = time->getTimeUtc();
                //std::cout << "Time: " << time <<  std::endl;
                ros::Time timeros = ros::Time::now();
                timestamp_sec = timeros.sec;
                timestamp_nsec = timeros.nsec;
			}
        }
        
        if(distance < 1)
        {
            error = 4;
        }

        {
            std::lock_guard<std::mutex> guard(m);
            observations[HORIZONTAL_ANGLE_VECTOR].push_back(horizontal_angle);
            observations[VERTICAL_ANGLE_VECTOR].push_back(vertical_angle);
            observations[DISTANCE_VECTOR].push_back(distance);
            observations[TIMESTAMPSEC_VECTOR].push_back(timestamp_sec);
            observations[TIMESTAMPNSEC_VECTOR].push_back(timestamp_nsec);
            observations[ERROR].push_back(error);
            size_vector+=1;
        }

    }
    catch(SSI::InvalidTrackingObservationsException&e )
    {
        const char* reason ="Unknown";
        if(e.isTiltOutOfRange())
        {
            reason = "TiltOutOfRange";
            error = 1;
        }
        else if (e.isWrongTargetDistance())
        {
            reason = "WrongTargetDistance";
            error = 2;
        }
        else
        {
            error = 3;
        }

        {
            std::lock_guard<std::mutex> guard(m);
            observations[HORIZONTAL_ANGLE_VECTOR].push_back(-1);
            observations[VERTICAL_ANGLE_VECTOR].push_back(-1);
            observations[DISTANCE_VECTOR].push_back(-1);
            observations[TIMESTAMPSEC_VECTOR].push_back(-1);
            observations[TIMESTAMPNSEC_VECTOR].push_back(-1);
            observations[ERROR].push_back(error);
            size_vector+=1;
        }

        printf("Tracking: %s due to %s\n", e.what(), reason);

    }
}

std::vector<std::vector<double>> ObservationListener::getObservations()
{
    std::lock_guard<std::mutex> guard(m);
    return observations;
}

int ObservationListener::getSizeVector()
{
    std::lock_guard<std::mutex> guard(m);
    return size_vector;
}

int ObservationListener::saveFile(std::string file_name, int precision)
{
    std::fstream csv_file;
	csv_file.open(file_name, std::ios::out);
	csv_file.setf(std::ios_base::fixed);
	csv_file.precision(precision);

	if(csv_file.is_open())
	{		
		double horizontal_angle;
		double vertical_angle;
		double distance;
		double timestamp_sec;
        double timestamp_nsec;
        int error;
		std::string comma = ",";

		std::cout << "File opened" << std::endl;
		csv_file << "Horizontal angles" << comma << "Vertical angles" << comma << "Distances" << comma << "Time stamps" << comma << "Error" << std::endl;
        
        //int number_of_measurements = observations[0].size();
        int number_of_measurements = size_vector;
		for(int i = 1; i < number_of_measurements; i++)
		{
			horizontal_angle = observations[HORIZONTAL_ANGLE_VECTOR][i];
			vertical_angle = observations[VERTICAL_ANGLE_VECTOR][i];
			distance = observations[DISTANCE_VECTOR][i];
			timestamp_sec = observations[TIMESTAMPSEC_VECTOR][i];
            timestamp_nsec = observations[TIMESTAMPNSEC_VECTOR][i];
            error = observations[ERROR][i];

            csv_file << horizontal_angle << comma << vertical_angle << comma << distance << comma << timestamp_sec << comma << timestamp_nsec << comma << error << std::endl;
		}
	}
	else
	{
		std::cout << "Problem in opening file" << std::endl;
        csv_file.close();
        std::cout << "File closed" << std::endl;
        return -1;
	}

    csv_file.close();
    std::cout << "File closed" << std::endl;

    return 0;
}
