#ifndef GREENHIGHPOWERLASERSTATE_H_
#define GREENHIGHPOWERLASERSTATE_H_

namespace SSI
{
	/**
	* Represents states for the Green High power laser
	*/
	enum GreenHighPowerLaserState
	{
		GPLS_Ok,					/**< The laser is in a good state. */
		GPLS_Overheat,			/**< The laser is close to overheating. */
		GPLS_OverheatShutdown,	/**< The laser got switched off because of overheating. */
		GPLS_Service				/**< The laser needs service. */
	};
}
#endif