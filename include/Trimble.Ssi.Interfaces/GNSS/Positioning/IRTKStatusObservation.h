#ifndef IRTKSTATUSOBSERVATION_H_
#define IRTKSTATUSOBSERVATION_H_

#include "IGNSSObservation.h"
#include "RTKErrorStatus.h"

namespace SSI
{
	/*
	* Represents a RTK status observation.
	*/
	class IRTKStatusObservation: public IGNSSObservation
	{
	public:

		virtual ~IRTKStatusObservation();
	
		/*
		* Gets the status.
		* @return RTKErrorStatus
		*/
		virtual RTKErrorStatus getRTKErrorStatus()=0;
	};
}
#endif