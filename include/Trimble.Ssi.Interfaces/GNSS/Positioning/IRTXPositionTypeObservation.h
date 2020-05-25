#ifndef IRTXPOSITIONTYPEOBSERVATION_H_
#define IRTXPOSITIONTYPEOBSERVATION_H_

#include "RTXPositionType.h"
#include "IGNSSObservation.h"

namespace SSI
{
	class IRTXPositionTypeObservation : public IGNSSObservation
	{
	public:
		~IRTXPositionTypeObservation(void);

		/*
		* Gets the type of the rtx position.
		* @return RTXPositionType
		*/
		virtual RTXPositionType getRTXPositionType() = 0;
	};
}
#endif