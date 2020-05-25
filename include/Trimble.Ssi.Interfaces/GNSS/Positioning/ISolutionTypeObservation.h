#ifndef ISOLUTIONTYPEOBSERVATION_H_
#define ISOLUTIONTYPEOBSERVATION_H_

#include "SolutionType.h"
#include "IGNSSObservation.h"

namespace SSI
{
	/*
	* Represents a solution type observation.
	*/
	class ISolutionTypeObservation: public IGNSSObservation
	{
	public:
		virtual ~ISolutionTypeObservation();
	
		/*
		* Gets the type of the solution.
		* @return SolutionType
		*/
		virtual SolutionType getSolutionType()=0;
	};
}
#endif