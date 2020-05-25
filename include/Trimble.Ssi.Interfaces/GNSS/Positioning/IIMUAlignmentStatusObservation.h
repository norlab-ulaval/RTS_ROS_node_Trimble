#ifndef IIMUALIGNMENTSTATUSOBSERVATION_H_
#define IIMUALIGNMENTSTATUSOBSERVATION_H_

#include "IGNSSObservation.h"
#include "IMUAlignmentStatus.h"

namespace SSI
{
	/*
	* Represents a IMU alignment status observation.
	*/
	class IIMUAlignmentStatusObservation: public IGNSSObservation
	{
	public:
		virtual ~IIMUAlignmentStatusObservation();
	
		/*
		* Gets the IMU alignment status.
		* @return IMUAlignmentStatus
		*/
		virtual IMUAlignmentStatus getIMUAlignmentStatus()=0;
	};
}
#endif