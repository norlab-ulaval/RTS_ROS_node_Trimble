#ifndef IGPSTIMEOBSERVATION_H_
#define IGPSTIMEOBSERVATION_H_

#include "IGNSSObservation.h"

namespace SSI
{
	/*
	* Represents a GPS time observation.
	*/
	class IGPSTimeObservation: public IGNSSObservation
	{
	public:
		virtual ~IGPSTimeObservation();
	
		/*
		* Gets the GPS time.
		* @return seconds
		*/
		virtual double getGPSTime()=0;

		/*
		* Gets the GPS and UTC time offset. offset = GPS - UTC
		* @return seconds
		*/
		virtual int getGPSUTCOffset()=0;
	};
}
#endif