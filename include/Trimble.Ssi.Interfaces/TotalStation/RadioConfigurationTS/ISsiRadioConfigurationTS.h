#ifndef ISSIRADIOCONFIGURATIONTS_H_
#define ISSIRADIOCONFIGURATIONTS_H_

#include "ISsiInterface.h"
#include "IRadioConfigurationTS.h"
#include "RadioMode.h"
#include <vector>

namespace SSI
{
	/**
	* Provides members to access the Radio configuration of an instrument.
	*/
	class ISsiRadioConfigurationTS :public ISsiInterface
	{
	public:
		virtual ~ISsiRadioConfigurationTS();

		/**
		* Returns an enumeration of available <see cref="RadioMode"/>.
		* Please be aware, that the underlying enumeration later may contain values, which are not known now.
		* @return An enumeration of available <see cref="RadioMode"/> objects.
		*/
		virtual std::vector<RadioMode> listSupportedRadioModes() const = 0;

		/**
		* Determines whether the specified mode is supported.
		* @param mode the RadioMode
		* @return true if the radio mode is supported, otherwise false
		*/
		virtual bool isSupported(RadioMode mode) const = 0;

		/**
		* Creates the radio configuration for the specified mode.
		* @param mode the RadioMode
		* @return IRadioConfigurationTS if the radio mode is supported, otherwise throws exception
		*/
		virtual IRadioConfigurationTS* createRadioConfiguration(RadioMode mode) = 0;

		/**
		* Gets an current radio configuration.
		* @return the IRadioConfigurationTS
		*/
		virtual IRadioConfigurationTS& getRadioConfiguration() = 0;

		/**
		* Changes the current Radio configuration.
		* @param radioConfiguration The radio configuration to be set.
		*/
		virtual void setRadioConfiguration(IRadioConfigurationTS& radioConfiguration) = 0;
	};
}
#endif
