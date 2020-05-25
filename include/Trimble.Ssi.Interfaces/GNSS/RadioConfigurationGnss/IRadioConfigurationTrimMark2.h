#ifndef IRADIOCONFIGURATIONTRIMMARK2_H_
#define IRADIOCONFIGURATIONTRIMMARK2_H_

#include "IRadioConfigurationTrimble.h"

namespace SSI
{
	/**
	* Represents a TrimMark II/IIe configuration.
	*/
	class IRadioConfigurationTrimMark2 : public virtual IRadioConfigurationTrimble
	{
	public:
		virtual ~IRadioConfigurationTrimMark2();
	};
}
#endif