#ifndef FOCUSSTATECHANGEDEVENT_H_
#define FOCUSSTATECHANGEDEVENT_H_

#include "FocusState.h"

namespace SSI
{
	/**
	* Event for indicating a change in the focus state.
	*/
	class FocusStateChangedEvent
	{
	public:
		/**
		* Initializes a new instance of the <see cref="FocusStateChangedEventArgs"/> class.
		* @param state The state.
		*/
		FocusStateChangedEvent(FocusState state);
		virtual ~FocusStateChangedEvent();

		/**
		* Gets the focus state.
		* @return The focus state.
		*/
		FocusState getState() const;
	private:
		FocusState _state;
	};
}
#endif