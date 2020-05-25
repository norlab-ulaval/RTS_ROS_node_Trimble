#ifndef BATTERYCHARGINGSTATE_H_
#define BATTERYCHARGINGSTATE_H_

namespace SSI
{
	/**
	*Represents the charging state of a battery.
	*Use IBattery::ChargingState to obtain the current charging state of a battery.
	*@see ISsiPower
	*/
	enum BatteryChargingState
	{
		BCS_NotSupported,	/**< It is not supported to query the battery charging state. */
		BCS_Charging,		/**< The battery is charging. */
		BCS_NotCharging		/**< The battery is not charging. */
	};
}
#endif
