#ifndef IHDSOLUTIONTYPEOBSERVATION_H_
#define IHDSOLUTIONTYPEOBSERVATION_H_

#include "IGNSSObservation.h"
#include "HDSolutionType.h"

namespace SSI
{
	/*
	* Represents a HD solutions type observation.
	*/
	class IHDSolutionTypeObservation: public IGNSSObservation
	{
	public:
		virtual ~IHDSolutionTypeObservation();
	
		/*
		* Gets the type of the HD solution.
		* @return HDSolutionType
		*/
		virtual HDSolutionType getHDSolutionType()=0;
	};
}
#endif