#ifndef BATTERYSTATE_H_
#define BATTERYSTATE_H_

namespace SSI
{
	/**
	* Represents the state of a battery.
	* Use IBattery::State to obtain the current power state of a battery.
	* @see ISsiPower
	*/
	enum BatteryState
	{
		BS_Unknown,		/**< unknown battery state. */
		BS_Ok,			/**< The battery state is ok. */
		BS_Low,			/**< Low battery state. */
		BS_Critical		/**< The battery state is critical. */
	};
}
#endif