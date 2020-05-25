#ifndef EXTERNALPOWERSTATE_H_
#define EXTERNALPOWERSTATE_H_

namespace SSI
{
	/**
	* Represents the state of an external power source.
	* Use IExternalPower::State to obtain the current state of an external power source.
	* @see IExternalPower
	* @see ISsiPower
	*/
	enum ExternalPowerState
	{
		EPS_Unknown,	/**< An unknown external power source state. */
		EPS_Ok,			/**< A state where the external power source is ok. */
		EPS_Critical	/**< A critical external power source state. */
	};
}
#endif