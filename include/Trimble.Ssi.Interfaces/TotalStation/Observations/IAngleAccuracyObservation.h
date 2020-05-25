#ifndef IANGLEACCURACYOBSERVATION_H_
#define IANGLEACCURACYOBSERVATION_H_

#include "ITSObservation.h"

namespace SSI
{
	/**
	* Represents an observation with angle accuracy values.
	* @see ObservationContainer
	* @see ISsiMeasurement
	* @see ISsiTracking
	*/
	class IAngleAccuracyObservation : public ITSObservation
	{
	public:
		virtual ~IAngleAccuracyObservation();

		/**
		* Get the horizontal angles in radian.
		* @return horizontal angles in radian.
		*/
		virtual double getHorizontalAngleAccuracy() const = 0;
	
		/**
		* Get the vertical angles in radian.
		* @return vertical angles in radian.
		*/
		virtual double getVerticalAngleAccuracy() const = 0;
	};
}
#endif