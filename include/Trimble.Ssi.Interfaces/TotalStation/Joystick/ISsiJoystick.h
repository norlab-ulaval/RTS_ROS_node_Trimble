#ifndef ISSIJOYSTICK_H_
#define ISSIJOYSTICK_H_

#include "ISsiInterface.h"
#include "JoystickTurnType.h"
#include "IJoystickTurn.h"
#include "ITurningStateChangedListener.h"
#include <vector>

namespace SSI
{
	/**
	* Access joystick functions of an instrument.
	*/
	class ISsiJoystick : public ISsiInterface
	{
	public:
		virtual ~ISsiJoystick();

		/**
		* register a listener for listening.
		* @param listener ITurningStateChangedListener to listen
		*/
		virtual void addTurningStateChangedListener(ITurningStateChangedListener& listener) = 0;

		/**
		* unsubscribe a listener from listening.
		* @param listener ITurningStateChangedListener to listen
		*/
		virtual void removeTurningStateChangedListener(ITurningStateChangedListener& listener) = 0;

		/**
		* Gets the state of the idle angle.
		* @return The state of the idle angle.
		*/
		virtual TurningState getTurningState() const = 0;

		/**
		* Get all available turn types.
		* @return the turn types
		*/
		virtual std::vector<JoystickTurnType> listSupportedTurnTypes() const = 0;

		/**
		* is the turn type supported.
		* @param JoystickTurnType to check
		* @return true if it is otherwise false
		*/
		virtual bool isTurnTypeSupported(JoystickTurnType joystickTurnType) const = 0;

		/**
		* create an instance of IJoystickTurn based on the JoystickTurnType.
		* @param JoystickTurnType the turn type
		* @return the instance
		*/
		virtual IJoystickTurn* createTurn(JoystickTurnType turnType) const = 0;

		/**
		* start the joystick movement in the given turn direction.
		* @param IJoystickTurn turn direction
		*/
		virtual void startJoystick(IJoystickTurn& turn) = 0;

		/**
		* stop the joystick movement.
		*/
		virtual void stopJoystick() = 0;
	};
}
#endif