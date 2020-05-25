#ifndef ISSIPOWER_H_
#define ISSIPOWER_H_

#include "ISsiInterface.h"
#include "ICurrentPowerSourceChangedListener.h"
#include "IPowerSource.h"

#include <vector>

namespace SSI
{
	/**
	* Provides members to access power supply information of an instrument.
	* For a brief description of features and usage of various ISsiInterface see [Guides: Interfaces](@ref Guides_Interfaces)
	*/
	class ISsiPower : public ISsiInterface
	{
	public:
		virtual ~ISsiPower();

		/**
		* register a power source changed listener.
		* @param ICurrentPowerSourceChangedListener the listener
		*/
		virtual void addCurrentPowerSourceChangedListener(ICurrentPowerSourceChangedListener& listener) = 0;

		/**
		* unsubscribe a power source changed listener.
		* @param ICurrentPowerSourceChangedListener the listener
		*/
		virtual void removeCurrentPowerSourceChangedListener(ICurrentPowerSourceChangedListener& listener) = 0;

		/**
		* get actual power source.
		* @return the actual power source
		*/
		virtual IPowerSource& getCurrentPowersource() const = 0;

		/**
		* get the power source.
		* @return all available power sources
		*/
		virtual std::vector<IPowerSource*> getPowerSources() const = 0;
	};
}
#endif
