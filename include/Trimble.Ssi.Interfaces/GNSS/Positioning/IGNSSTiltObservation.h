#ifndef IGNSSTILTOBSERVATION_H_
#define IGNSSTILTOBSERVATION_H_

#include "IGNSSObservation.h"

namespace SSI
{
	class IGNSSTiltObservation: public IGNSSObservation
	{
	public:

		/*
		* Gets the pitch.
		* @return The pitch.
		*/
		virtual double getPitch()=0;

		/*
		* Gets the roll.
		* @return The roll.
		*/
		virtual double getRoll()=0;

		/*
		* Gets the yaw.
		* @return The yaw.
		*/
		virtual double getYaw()=0;

		virtual ~IGNSSTiltObservation();
	};
}
#endif