#ifndef TURNINGSTATECHANGEDEVENT_H_
#define TURNINGSTATECHANGEDEVENT_H_

#include "TurningState.h"

namespace SSI
{
	/**
	* Provides data for the <see cref="ISsiJoystick.TurningStateChanged"/> event.
	* <seealso cref="ISsiJoystick.TurningStateChanged"/>
	*/
	class TurningStateChangedEvent
	{
	public:
		virtual ~TurningStateChangedEvent();
	
		/**
		* Initializes a new instance of the <see cref="TurningStateChangedEventArgs" /> class.
		* @param turningState State of the turning.
		*/
		TurningStateChangedEvent(TurningState turningState);

		/**
		* Gets the state of the turning.
		* @return The state of the turning.
		*/
		TurningState getTurningState() const;
	private:
		/**
		* Sets the state of the turning.
		* @param turningState The state of the turning.
		*/
		void setTurningState(TurningState turningState);
		TurningStateChangedEvent();
		TurningStateChangedEvent(const TurningStateChangedEvent& copyMe);
		TurningStateChangedEvent& operator=(const TurningStateChangedEvent&);
		TurningState _turningState; /**< the turning state. */
	};
}
#endif