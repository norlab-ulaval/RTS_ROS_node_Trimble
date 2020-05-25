#ifndef TURNINGSTATE_H_
#define TURNINGSTATE_H_

namespace SSI
{
	/**
	* shows available TurnToStates.
	*/
	enum TurningState
	{
		TS_Starting,	/**< The starting */
		TS_Turning,		/**< The turning */
		TS_Stopping,	/**< The stopping */
		TS_NotTurning	/**< The not turning */
	};
}
#endif