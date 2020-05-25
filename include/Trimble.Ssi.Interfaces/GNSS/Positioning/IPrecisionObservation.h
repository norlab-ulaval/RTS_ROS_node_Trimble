#ifndef IPRECISIONOBSERVATION_H_
#define IPRECISIONOBSERVATION_H_

#include "IGNSSObservation.h"

namespace SSI
{
	/*
	* Represents a precision observation.
	*/
	class IPrecisionObservation: public IGNSSObservation {
	public:
		virtual ~IPrecisionObservation();

		/*
		* Gets the vertical precision.
		* @return double
		*/
		virtual double getVerticalPrecision()=0;

		/*
		* Gets the horizontal precision.
		* @return douoble
		*/
		virtual double getHorizontalPrecision()=0;
	};
}
#endif