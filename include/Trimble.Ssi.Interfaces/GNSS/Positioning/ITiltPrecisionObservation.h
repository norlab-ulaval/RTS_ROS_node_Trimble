#ifndef ITILTPRECISIONOBSERVATION_H_
#define ITILTPRECISIONOBSERVATION_H_

#include "IGNSSObservation.h"

namespace SSI
{
	/*
	*  Represents the tilt precision observation
	*/
	class ITiltPrecisionObservation: public IGNSSObservation
	{
	public:
		virtual ~ITiltPrecisionObservation();

		/*
		* Gets the pitch standard deviation.
		* @return The pitch standard deviation.
		*/
		virtual double getPitchPrecision()=0;

		/*
		* Gets the roll standard deviation.
		* @return The roll standard deviation.
		*/
		virtual double getRollPrecision()=0;

		/*
		* Gets the yaw standard deviation.
		* @return The yaw standard deviation.
		*/
		virtual double getYawPrecision()=0;
	};
}
#endif