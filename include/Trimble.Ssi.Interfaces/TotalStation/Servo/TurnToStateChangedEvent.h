#ifndef TURNTOSTATECHANGEDEVENT_H_
#define TURNTOSTATECHANGEDEVENT_H_

#include "TurnToState.h"

namespace SSI
{
	/**
	* Provides data for the <see cref="ISsiServo.TurnToStateChanged"/> event.
	* <seealso cref="ISsiServo.TurnToStateChanged"/>
	*/
	class TurnToStateChangedEvent
	{
	public:
		/**
		* Initializes a new instance of the <see cref="TurnToStateChangedEventArgs"/> class.
		* @param turntostate The turntostate.
		*/
		TurnToStateChangedEvent(TurnToState turntostate);
		virtual ~TurnToStateChangedEvent();

		/**
		* Gets the state of the survey.
		* @eturn The state of the survey.
		*/
		virtual TurnToState getTurnToState() const;
	private:
		/**
		* Sets the state of the survey.
		* @param turntostate The state of the survey.
		*/
		virtual void setTurnToState(TurnToState turntostate);
		TurnToState _turnToState;
	};
}
#endif