#ifndef IRADIOCONFIGURATIONPACIFICCREST_H_
#define IRADIOCONFIGURATIONPACIFICCREST_H_

#include "IRadioConfigurationTrimble.h"
#include "IRadioConfigurationSensitivity.h"
#include "IRadioConfigurationScrambler.h"
#include "IRadioConfigurationForwardErrorCorrection.h"

namespace SSI
{
	/**
	* Represents a Pacific Crest configuration.
	*/
	class IRadioConfigurationPacificCrest : public virtual IRadioConfigurationTrimble, public virtual IRadioConfigurationSensitivity,
		public virtual IRadioConfigurationScrambler, public virtual IRadioConfigurationForwardErrorCorrection
	{
	public:
		virtual ~IRadioConfigurationPacificCrest();

	};
}
#endif