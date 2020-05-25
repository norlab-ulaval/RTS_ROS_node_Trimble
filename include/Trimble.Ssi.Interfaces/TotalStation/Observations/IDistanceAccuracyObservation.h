#ifndef IDISTANCEACCURACYOBSERVATION_H_
#define IDISTANCEACCURACYOBSERVATION_H_

#include "ITSObservation.h"

namespace SSI
{
	/**
	* Represents an observation with distance accuracy value.
	* @see ObservationContainer
	* @see ISsiMeasurement
	* @see ISsiTracking
	*/
	class IDistanceAccuracyObservation : public ITSObservation
	{
	public:
		virtual ~IDistanceAccuracyObservation();
		
		/**
		* Gets the accuracy of the slope distance.
		* @return accuracy of the slope distance.
		*/
		virtual double getSlopeDistanceAccuracy() const = 0;
	};
}
#endif