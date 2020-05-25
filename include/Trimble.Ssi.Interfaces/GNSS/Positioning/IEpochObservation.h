#ifndef IEPOCHOBSERVATION_H_
#define IEPOCHOBSERVATION_H_

#include "IGNSSObservation.h"

namespace SSI
{
	/*
	* Represents a epoch observation.
	*/
	class IEpochObservation: public IGNSSObservation
	{
	public:
		virtual ~IEpochObservation();

		/*
		* Gets the epoch.
		* @return int
		*/
		virtual int getEpoch()=0;
	};
}
#endif