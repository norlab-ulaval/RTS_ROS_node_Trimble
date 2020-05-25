#ifndef IDISTANCEPRECISIONOBSERVATION_H_
#define IDISTANCEPRECISIONOBSERVATION_H_

#include "ITSObservation.h"

namespace SSI
{
	/**
	* Represents an observation with distance precision value.
	* @see ObservationContainer
	* @see ISsiMeasurement
	* @see ISsiTracking
	* @see IMeasurementParameterDistancePrecision
	*/
	class IDistancePrecisionObservation : public ITSObservation
	{
	public:
		virtual ~IDistancePrecisionObservation();
		
		/**
		* Gets the precision of the slope distance.
		* @return Precision of the slope distance.
		*/
		virtual double getSlopeDistancePrecision() const = 0;
	};
}
#endif