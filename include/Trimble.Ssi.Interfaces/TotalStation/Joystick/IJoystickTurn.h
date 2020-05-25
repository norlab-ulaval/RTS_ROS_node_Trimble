#ifndef IJOYSTICKTURN_H_
#define IJOYSTICKTURN_H_

#include "JoystickTurnType.h"

namespace SSI
{
	/**
	* Represents a basic joystick turn.
	*/
	class IJoystickTurn
	{
	public:
		virtual ~IJoystickTurn();

		/**
		* get a joystick turn type.
		* @return a joystick turn type
		*/
		virtual JoystickTurnType getJoystickTurnType() const = 0;
	};
}
#endif