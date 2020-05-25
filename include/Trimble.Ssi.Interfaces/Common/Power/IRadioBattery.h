#ifndef IRADIOBATTERY_H_
#define IRADIOBATTERY_H_

#include "IBattery.h"

namespace SSI
{
	/**
	* Represents a radio battery.
	* @see ISsiPower
	*/
	class IRadioBattery : public IBattery
	{
	public:
		virtual ~IRadioBattery();
	};
}
#endif