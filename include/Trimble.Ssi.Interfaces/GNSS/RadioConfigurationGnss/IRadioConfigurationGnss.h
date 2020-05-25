#ifndef IRADIOCONFIGURATIONGNSS_H_
#define IRADIOCONFIGURATIONGNSS_H_

#include "RadioProtocolType.h"

namespace SSI
{
	/**
	*  Base interface for radio parameters
	*/
	class IRadioConfigurationGnss
	{
	public:
		virtual ~IRadioConfigurationGnss();

		/**
		* Gets the type of the radio configuration.
		* @return the type of the radio configuration.
		*/
		virtual RadioProtocolType getRadioProtocol() const = 0;
	};
}
#endif