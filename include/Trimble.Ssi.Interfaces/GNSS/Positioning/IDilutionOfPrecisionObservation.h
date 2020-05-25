#ifndef IDILUTIONOFPRECISIONOBSERVATION_H_
#define IDILUTIONOFPRECISIONOBSERVATION_H_

#include "IGNSSObservation.h"

namespace SSI
{
	/*
	* Represents a dilution of precision observation.
	*/
	class IDilutionOfPrecisionObservation: public IGNSSObservation
	{
	public:
		virtual ~IDilutionOfPrecisionObservation();

		/*
		* Gets the HDOP.
		* @return HDOP
		*/
		virtual double getHDOP()=0;

		/*
		* Gets the VDOP.
		* @return VDOP
		*/
		virtual double getVDOP()=0;

		/*
		* Gets the PDOP.
		* @return PDOP
		*/
		virtual double getPDOP()=0;
	};
}
#endif