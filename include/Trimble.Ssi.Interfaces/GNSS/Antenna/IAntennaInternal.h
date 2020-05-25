#ifndef IANTENNAINTERNAL_H_
#define IANTENNAINTERNAL_H_

#include "IAntenna.h"

namespace SSI
{
	/*
	* Internal Antenna base interface.
	*/
	class IAntennaInternal : public IAntenna
	{
	public:
		virtual ~IAntennaInternal();
	};
}
#endif
