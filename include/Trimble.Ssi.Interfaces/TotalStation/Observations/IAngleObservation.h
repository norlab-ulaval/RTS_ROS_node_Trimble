#ifndef IANGLEOBSERVATION_H_
#define IANGLEOBSERVATION_H_

#include "../Common/SphericalAngles.h"
#include "ITSObservation.h"

namespace SSI
{
	/**
	* Represents an angle observation.
	* @see ObservationContainer
	* @see ISsiMeasurement
	* @see ISsiTracking
	*/
	class IAngleObservation : public ITSObservation
	{
	public:
		virtual ~IAngleObservation();
		
		/**
		* Get the spherical angles in radian.
		* @return Spherical angles in radian.
		*/
		virtual const SphericalAngles& getAngles() const = 0;
	};
}
#endif