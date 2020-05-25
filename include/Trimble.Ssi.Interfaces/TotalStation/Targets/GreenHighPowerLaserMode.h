#ifndef GREENHIGHPOWERLASERMODE_H_
#define GREENHIGHPOWERLASERMODE_H_

namespace SSI
{
	/**
	* Represents the laser execution Mode of a GreenHighPower direct reflex target
	*/
	enum GreenHighPowerLaserMode
	{
        GPLM_Off, /**< Green high power laser is switched off. */
        GPLM_Low, /**< Green high power laser is in low power mode. */
        GPLM_High /**< Green high power laser is in high power mode. */
	};
}
#endif