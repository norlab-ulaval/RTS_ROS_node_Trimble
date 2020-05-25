#ifndef IMAGNETICDISTURBANCEOBSERVATION_H_
#define IMAGNETICDISTURBANCEOBSERVATION_H_

#include "IGNSSObservation.h"

namespace SSI
{
	/*
	* A debug tilt observation
	*/
	class IMagneticDisturbanceObservation: public IGNSSObservation
	{
	public:
		virtual ~IMagneticDisturbanceObservation();
		/*
		* Gets the magnetic direction disturbance.
		* @return The magnetic direction disturbance.
		*/
		virtual double getMagneticDirectionDisturbance()=0;

		/*
		* Gets the magnetic strength disturbance.
		* @return The magnetic strength disturbance.
		*/
		virtual double getMagneticStrengthDisturbance()=0;
	};
}
#endif