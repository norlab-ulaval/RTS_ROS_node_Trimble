#ifndef IGROUNDPRECISIONOBSERVATION_H_
#define IGROUNDPRECISIONOBSERVATION_H_

#include "IPrecisionObservation.h"

namespace SSI
{
	/*
	*  Precision observation at ground
	*/
	class IGroundPrecisionObservation: public IPrecisionObservation
	{
	public:
		virtual ~IGroundPrecisionObservation();
	};
}
#endif