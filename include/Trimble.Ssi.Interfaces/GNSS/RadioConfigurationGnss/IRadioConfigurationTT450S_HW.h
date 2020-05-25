#ifndef IRADIOCONFIGURATIONTT450S_HW_H_
#define IRADIOCONFIGURATIONTT450S_HW_H_

#include "IRadioConfigurationTrimble.h"

namespace SSI
{
	/**
	* Represents a TT450S (HW) configuration.
	*/
	class IRadioConfigurationTT450S_HW : public virtual IRadioConfigurationTrimble
	{
	public:
		virtual ~IRadioConfigurationTT450S_HW();
	};
}
#endif