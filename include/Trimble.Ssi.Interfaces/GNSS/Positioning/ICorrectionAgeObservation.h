#ifndef ICORRECTIONAGEOBSERVATION_H_
#define ICORRECTIONAGEOBSERVATION_H_

#include "IGNSSObservation.h"

namespace SSI
{
	/*
	* Represents Correction age observation.
	*/
	class ICorrectionAgeObservation: public IGNSSObservation
	{
	public:
		virtual ~ICorrectionAgeObservation();

		/*
		* Gets the age.
		* @return Age
		*/
		virtual double getAge()=0;
	};
}
#endif