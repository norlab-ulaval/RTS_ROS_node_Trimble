#ifndef IRATIOATINITIALIZATIONOBSERVATION_H_
#define IRATIOATINITIALIZATIONOBSERVATION_H_

#include "IGNSSObservation.h"

namespace SSI
{
	/**
	* Represents a ratio at initialization observation.
	*/
	class IRatioAtInitializationObservation: public IGNSSObservation
	{
	public:
		virtual ~IRatioAtInitializationObservation();

		/*
		* Gets the ratio.
		* @return ratio
		*/
		virtual double getRatio()=0;
	};
}
#endif