#ifndef ISSISTARTUPCONFIGURATION_H_
#define ISSISTARTUPCONFIGURATION_H_

#include "ISsiInterface.h"
#include "StartupMode.h"
#include <vector>

namespace SSI
{
	/**
	* Provides members to access the Startup configuration of an instrument.
	*/
	class ISsiStartupConfiguration :public ISsiInterface
	{
	public:
		virtual ~ISsiStartupConfiguration();

		/**
		* Returns an enumeration of available <see cref="StartupMode"/>.
		* Please be aware, that the underlying enumeration later may contain values, which are not known now.
		* @return An enumeration of available <see cref="StartupMode"/> objects.
		*/
		virtual std::vector<StartupMode> listSupportedStartupModes() const = 0;

		/**
		* Determines whether the specified mode is supported.
		* @param mode the StartupMode
		* @return true if the startup mode is supported, otherwise false
		*/
		virtual bool isSupported(StartupMode mode) const = 0;

		/**
		* Gets an <see cref="StartupMode"/>.
		* @return the startup mode
		*/
		virtual StartupMode getStartupMode() = 0;

		/**
		* Changes the current Startup mode.
		* @param startupMode The Startup mode to be set as current mode.
		*/
		virtual void setStartupMode(StartupMode mode) = 0;
	};
}
#endif
