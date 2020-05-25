#ifndef IRADIOCONFIGURATIONSATEL_H_
#define IRADIOCONFIGURATIONSATEL_H_

#include "IRadioConfigurationPacificCrest.h"

namespace SSI
{
	/**
	*  Represents a SATEL configuration.
	*/
	class IRadioConfigurationSatel : public virtual IRadioConfigurationPacificCrest
	{
	public:
		virtual ~IRadioConfigurationSatel();
	};
}
#endif