#ifndef IRADIOCONFIGURATIONTRIMBLE_H_
#define IRADIOCONFIGURATIONTRIMBLE_H_

#include "IRadioConfigurationOutputPower.h"
#include "IRadioConfigurationAirLinkSpeed.h"

namespace SSI
{
	/**
	* Represents a Trimble radio configuration.
	*/
	class IRadioConfigurationTrimble :public virtual IRadioConfigurationOutputPower, public virtual IRadioConfigurationAirLinkSpeed
	{
	public:
		virtual ~IRadioConfigurationTrimble();
	};
}
#endif