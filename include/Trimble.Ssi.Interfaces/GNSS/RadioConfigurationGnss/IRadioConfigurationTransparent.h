#ifndef IRADIOCONFIGURATIONTRANSPARENT_H_
#define IRADIOCONFIGURATIONTRANSPARENT_H_

#include "IRadioConfigurationPacificCrest.h"

namespace SSI
{
	/**
	* Represents a Transparent configuration.
	*/
	class IRadioConfigurationTransparent : public virtual IRadioConfigurationPacificCrest
	{
	public:
		virtual ~IRadioConfigurationTransparent();

	};
}
#endif