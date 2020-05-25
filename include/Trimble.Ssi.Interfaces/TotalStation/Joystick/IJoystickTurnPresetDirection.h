#ifndef IJOYSTICKTURNPRESETDIRECTION_H_
#define IJOYSTICKTURNPRESETDIRECTION_H_

#include "DirectionPreset.h"
#include "IJoystickTurn.h"

namespace SSI
{
	/**
	* Represents an <see cref="IJoystickTurn"/> for variable directions and speed.
	*/
	class IJoystickTurnPresetDirection : public IJoystickTurn
	{
	public:
		virtual ~IJoystickTurnPresetDirection();

		/**
		* Gets the direction preset.
		* @return The direction preset.
		*/
		virtual DirectionPreset getDirectionPreset() const = 0;
	
		/**
		* Sets the direction preset.
		* @param directionPreset The direction preset.
		*/
		virtual void setDirectionPreset(DirectionPreset directionPreset) = 0;

		/**
		* Gets the speed [Radiant/s].
		* @return the speed
		*/
		virtual double getSpeed() const = 0;

		/**
		* Sets the speed [Radiant/s].
		* @param speed the speed
		*/
		virtual void setSpeed(double speed) = 0;

		/**
		* Gets the max speed [Radiant/s].
		* @return the maximum speed.
		*/
		virtual double getMaximumSpeed() const = 0;
	};
}
#endif