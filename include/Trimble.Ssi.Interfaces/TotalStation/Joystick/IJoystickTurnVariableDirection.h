#ifndef IJOYSTICKTURNVARIABLEDIRECTION_H_
#define IJOYSTICKTURNVARIABLEDIRECTION_H_

#include "IJoystickTurn.h"

namespace SSI
{
	/**
	* Represents an <see cref="IJoystickTurn"/> for variable directions and speed.
	*/
	class IJoystickTurnVariableDirection : public IJoystickTurn
	{
	public:
		virtual ~IJoystickTurnVariableDirection();
	
		/**
		* Gets the horizontal speed [Radiant/s].
		* @return The horizontal speed.
		*/
		virtual double getHorizontalSpeed() const = 0;

		/**
		* Sets the horizontal speed [Radiant/s].
		* @param speed The horizontal speed.
		*/
		virtual void setHorizontalSpeed(double speed) = 0;

		/**
		* Gets the vertical speed [Radiant/s].
		* @return The vertical speed.
		*/
		virtual double getVerticalSpeed() const = 0;

		/**
		* Sets the vertical speed [Radiant/s].
		* @param speed The vertical speed.
		*/
		virtual void setVerticalSpeed(double speed) = 0;

		/**
		* Gets the maximum speed [Radiant/s].
		* @return the maximum speed
		*/
		virtual double getMaximumSpeed() const = 0;
	};
}
#endif