#ifndef IINTERNALBATTERY_H_
#define IINTERNALBATTERY_H_

#include "IBattery.h"

namespace SSI
{
	/**
	* Represents an internal battery.
	* @see ISsiPower
	*/
	class IInternalBattery : public IBattery
	{
	public:
		virtual ~IInternalBattery();
	};
}
#endif