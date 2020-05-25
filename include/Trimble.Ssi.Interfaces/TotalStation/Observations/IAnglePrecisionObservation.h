#ifndef IANGLEPRECISIONOBSERVATION_H_
#define IANGLEPRECISIONOBSERVATION_H_

#include "ITSObservation.h"

namespace SSI
{
	/**
	* Represents an observation with angle precision values.
	* @see ObservationContainer
	* @see ISsiMeasurement
	* @see ISsiTracking
	*/
	class IAnglePrecisionObservation : public ITSObservation
	{
	public:
		virtual ~IAnglePrecisionObservation();

		/**
		* Get the horizontal angles in radian.
		* @return horizontal angles in radian.
		*/
		virtual double getHorizontalAnglePrecision() const = 0;
	
		/**
		* Get the vertical angles in radian.
		* @return vertical angles in radian.
		*/
		virtual double getVerticalAnglePrecision() const = 0;
	};
}
#endif