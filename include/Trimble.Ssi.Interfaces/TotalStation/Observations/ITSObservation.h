#ifndef ITSOBSERVATION_H_
#define ITSOBSERVATION_H_

#include "TSObservationType.h"

namespace SSI
{
	/**
	* Represents a basic synchronized observation.
	* Use ObservationContainer::GetObservation to obtain a specific observation.
	* @see ObservationContainer
	* @see ISsiMeasurement
	* @see ISsiTracking
	*/
	class ITSObservation
	{
	public:
		virtual ~ITSObservation();

		/**
		* get the observation type.
		* @return the observation type
		*/
		virtual TSObservationType getObservationType() const = 0;
		virtual ITSObservation& clone() = 0;
	};
}
#endif