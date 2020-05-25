#ifndef DIRECTIONPRESET_H_
#define DIRECTIONPRESET_H_

namespace SSI
{
	/**
	* Represents a pre configured direction.
	*/
	enum DirectionPreset
	{
		DP_Up,			/**< The direction for the joystick turn is upwards.*/
		DP_UpRight,		/**< The direction for the joystick turn is upwards and right.*/
		DP_Right,		/**< The direction for the joystick turn is right.*/
		DP_DownRight,	/**< The direction for the joystick turn is downwards and right.*/
		DP_Down,		/**< The direction for the joystick turn is downwards.*/
		DP_DownLeft,	/**< The direction for the joystick turn is downwards and left.*/
		DP_Left,		/**< The direction for the joystick turn is left.*/
		DP_UpLeft		/**< The direction for the joystick turn is upwards and left.*/
	};
}
#endif