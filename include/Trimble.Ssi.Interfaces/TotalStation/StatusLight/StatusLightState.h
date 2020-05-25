#ifndef STATUSLIGHTSTATE_H
#define STATUSLIGHTSTATE_H

namespace SSI
{
	/**
	* Represents the state of the status light.
	*/
	enum StatusLightState
	{
		/**
		* Statuslight is off.
		*/
		Off,

		/**
		* Statuslight is on.
		*/
		On,

		/**
		* Statuslight is blinking slow.
		*/
		Slow,

		/**
		* Statuslight is blinking fast.
		*/
		Fast,

		/**
		* Statuslight is blinking fast, if target is locked.
		*/
		FastIfLocked,

		/**
		* Statuslight is on, if target is locked.
		*/
		OnIfLocked,

		/**
		* Statuslight is on, if target is unlocked.
		*/
		OnIfUnLocked
	};
}
#endif