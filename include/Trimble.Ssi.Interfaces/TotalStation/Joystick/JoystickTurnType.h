#ifndef JOYSTICKTURNTYPE_H_
#define JOYSTICKTURNTYPE_H_

namespace SSI
{
	/**
	* represents a turn type of a joystick.
	*/
	enum JoystickTurnType
	{
		JTT_VariableDirection,	/**< The turn type for variable directions*/
		JTT_PresetDirection		/**< The turn type for direction presets*/
	};
}
#endif