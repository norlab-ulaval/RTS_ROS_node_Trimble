#ifndef ITURNTOSTATECHANGEDLISTENER_H_
#define ITURNTOSTATECHANGEDLISTENER_H_

#include "TurnToStateChangedEvent.h"

namespace SSI
{
	/**
	* listens for turn to state changes.
	*/
	class ITurnToStateChangedListener
	{
	public:
		virtual ~ITurnToStateChangedListener();
	
		/**
		* a turn to state changed event occurred.
		* @param TurnToStateChangedEvent the event
		*/
		virtual void turnToStateChanged(const TurnToStateChangedEvent& turnToStateChangedEvent) = 0;
	};
}
#endif