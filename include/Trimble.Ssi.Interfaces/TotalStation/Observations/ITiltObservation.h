#ifndef ITILTOBSERVATION_H_
#define ITILTOBSERVATION_H_

#include "ITSObservation.h"

namespace SSI
{
	/**
	* Represents a tilt observation.
	* @see ObservationContainer
	* @see ISsiMeasurement
	* @see ISsiTracking
	*/
	class ITiltObservation : public ITSObservation
	{
	public:
		virtual ~ITiltObservation();

		/**
		* Gets the trunnion axis angle in radian.
		* @return Radian value representing the sighting axis.
		*/
		virtual double getTrunnion() const = 0;
	
		/**
		* Gets the sighting axis value in radian.
		* @return Radian value representing the sighting axis.
		*/
		virtual double getSighting() const = 0;
	};
}
#endif