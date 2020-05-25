#ifndef IEXTENDEDDILUTIONOFPRECISIONOBSERVATION_H_
#define IEXTENDEDDILUTIONOFPRECISIONOBSERVATION_H_

#include "IDilutionOfPrecisionObservation.h"

namespace SSI
{
	/*
	* Represents a extended dilution of precision observation.
	*/
	class IExtendedDilutionOfPrecisionObservation: public IDilutionOfPrecisionObservation
	{
	public:

		virtual ~IExtendedDilutionOfPrecisionObservation();
	
		/*
		* Gets the TDOP.
		* @return double
		*/
		virtual double getTDOP()=0;

		/*
		* Gets the GDOP.
		* @return double
		*/
		virtual double getGDOP()=0;
	};
}
#endif