#ifndef IBATTERY_H_
#define IBATTERY_H_

#include "IPowerSource.h"
#include "BatteryState.h"
#include "BatteryChargingState.h"

namespace SSI
{
	/**
	* Represents a battery providing access to its information.
	* @see ISsiPower
	*/
	class IBattery : public IPowerSource
	{
	public:
		virtual ~IBattery();

		/**
		* Gets the battery level in percentage (0-100).
		* @return the battery level
		*/
		virtual int getLevel() const = 0;

		/**
		* Gets the battery status.
		* This is basically the driver interpretation of Level.
		* Could be used for conditional behavior in an application.
		* @return the state of the battery.
		*/
		virtual BatteryState getBatteryState() const = 0;

		/**
		* Gets the charging state of the battery.
		* @return the charging state
		*/
		virtual BatteryChargingState getBatteryChargingState() const = 0;
	};
}
#endif
