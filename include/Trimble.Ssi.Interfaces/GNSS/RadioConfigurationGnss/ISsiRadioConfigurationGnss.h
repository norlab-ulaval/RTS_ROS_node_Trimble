#ifndef ISSIRADIOCONFIGURATIONGNSS_H_
#define ISSIRADIOCONFIGURATIONGNSS_H_

#include "ISsiInterface.h"
#include "RadioProtocolType.h"
#include "IRadioConfigurationGnss.h"
#include <vector>

namespace SSI
{
	/**
	* Represents an internal GNSS radio configuration.
	*/
	class ISsiRadioConfigurationGnss : public ISsiInterface
	{
	public:
		virtual ~ISsiRadioConfigurationGnss();

		/**
		* Lists the supported radio protocols.
		* @return the supported radio protocols.
		*/
		virtual std::vector<RadioProtocolType> listSupportedRadioProtocols() const = 0;

		/**
		* Determines whether the specified radio protocol is supported.
		* @param radioProtocol.
		* @return true if supported; otherwise false
		*/
		virtual bool isSupported(RadioProtocolType radioProtocol) const = 0;

		/**
		* Creates a new instance of <see cref="IRadioConfigurationGnss"/>.
		* @param RadioProtocolType the mode
		* @return the radio configuration
		*/
		virtual IRadioConfigurationGnss* createRadioConfiguration(RadioProtocolType mode) = 0;

		/**
		* Gets an <see cref="IRadioConfigurationGnss"/>.
		* @return the radio configuration beta
		*/
		virtual IRadioConfigurationGnss& getRadioConfiguration() = 0;

		/**
		* Changes the current radio configuration.
		* @param radioConfiguration The radio configuration to be set as current configuration.
		*/
		virtual void setRadioConfiguration(IRadioConfigurationGnss& radioConfiguration) = 0;
	};
}
#endif