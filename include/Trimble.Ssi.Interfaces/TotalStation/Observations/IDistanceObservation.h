#ifndef IDISTANCEOBSERVATION_H_
#define IDISTANCEOBSERVATION_H_

#include "ITSObservation.h"

namespace SSI
{
	/**
	* Represents a distance observation.
	* @see ObservationContainer
	* @see ISsiMeasurement
	* @see ISsiTracking
	*/
	class IDistanceObservation : public ITSObservation
	{
	public:
		virtual ~IDistanceObservation();
	
		/**
		* get the slope distance in meters.
		* @return the slope distance
		*/
		virtual double getSlopeDistance() const = 0;
	};
}
#endif