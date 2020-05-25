#ifndef IRADIOCONFIGURATIONSENITIVITY_H_
#define IRADIOCONFIGURATIONSENITIVITY_H_

#include "IRadioConfigurationGnss.h"
#include "RadioSensitivityMode.h"
#include <vector>

namespace SSI
{
	/**
	* The radio parameter for changing the radio sensitivity
	*/
	class IRadioConfigurationSensitivity : public virtual IRadioConfigurationGnss
	{
	public:
		virtual ~IRadioConfigurationSensitivity();

		/**
		* Lists the supported radio sensitivities.
		* @return the supported radio sensitivities.
		*/
		virtual std::vector<RadioSensitivityMode> listSupportedSensitivityModes() const = 0;

		/**
		* Determines whether the specified radio sensitivitiy is supported.
		* @param radioSensitivity.
		* @return true if supported; otherwise false
		*/
		virtual bool isSensitivityModeSupported(RadioSensitivityMode radioSensitivity) const = 0;

		/**
		* Gets the radioSensitivity.
		* @return the radioSensitivity
		*/
		virtual RadioSensitivityMode getSensitivity() const = 0;

		/**
		* Sets the radioSensitivity.
		* @param the radioSensitivity
		*/
		virtual void setSensitivity(RadioSensitivityMode radioSensitivity) = 0;
	};
}
#endif