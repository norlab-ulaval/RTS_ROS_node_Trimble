#ifndef IRMSOBSERVATION_H_
#define IRMSOBSERVATION_H_

#include "IGNSSObservation.h"

namespace SSI
{
	/*
	* Represents a RMS observation.
	*/
	class IRMSObservation: public IGNSSObservation
	{
	public:
		virtual ~IRMSObservation();

		/*
		* Gets the RMS.
		* @return double
		*/
		virtual double getRMS()=0;
	};
}
#endif