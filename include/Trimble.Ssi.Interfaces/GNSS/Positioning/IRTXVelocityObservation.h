#ifndef IRTXVELOCITYOBSERVATION_H
#define IRTXVELOCITYOBSERVATION_H

#include "IGNSSObservation.h"

namespace SSI
{
	class IRTXVelocityObservation : public IGNSSObservation
	{
	public:
		~IRTXVelocityObservation(void);

		/*
		* ITRF ECEF-X velocity is the X velocity (metres/year) being added to ITRF Current Epoch coordinates to model tectonic plate motion
		*/
		virtual double getX() = 0;

		/*
		* ITRF ECEF-Y velocity is the Y velocity (metres/year) being added to ITRF Current Epoch coordinates to model tectonic plate motion
		*/
		virtual double getY() = 0;

		/*
		* ITRF ECEF-Z velocity is the Z velocity (metres/year) being added to ITRF Current Epoch coordinates to model tectonic plate motion
		*/
		virtual double getZ() = 0;
	};
}
#endif