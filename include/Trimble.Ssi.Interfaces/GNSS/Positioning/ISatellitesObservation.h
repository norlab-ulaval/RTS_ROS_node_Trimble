#ifndef ISATELLITESOBSERVATION_H_
#define ISATELLITESOBSERVATION_H_

#include "IGNSSObservation.h"

namespace SSI
{
	/*
	* Represents a satellite observation.
	*/
	class ISatellitesObservation: public IGNSSObservation
	{
	public:
		virtual ~ISatellitesObservation();

		/*
		* Gets the number of satellites.
		* @return number of satellites
		*/
		virtual int getNumberOfSatellites()=0;
	};
}
#endif