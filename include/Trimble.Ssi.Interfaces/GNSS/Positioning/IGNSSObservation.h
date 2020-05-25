#ifndef IGNSSOBSERVATION_H_
#define IGNSSOBSERVATION_H_

#include "GNSSObservationType.h"

namespace SSI
{
	/*
	* Represents a basic synchronized observation.
	* @remark Use IGNSSObservationContainer.GetObservation to obtain a specific observation.
	*/
	class IGNSSObservation
	{
	public:
		virtual ~IGNSSObservation();

		/*
		* Gets the type of the observation.
		* @return ObservationType
		*/
		virtual GNSSObservationType getObservationType()=0;

		virtual IGNSSObservation& clone() = 0;
	};
}
#endif