#ifndef ITURNINGSTATECHANGEDLISTENER_H_
#define ITURNINGSTATECHANGEDLISTENER_H_

#include "TurningStateChangedEvent.h"

namespace SSI
{
	/**
	* Listens for changed turning states.
	*/
	class ITurningStateChangedListener
	{
	public:
		virtual ~ITurningStateChangedListener();
	
		/**
		* receives the event message when changes occur.
		* @param TurningSateChangedEvent the event that occured
		*/
		virtual void onTurningStateChanged(const TurningStateChangedEvent& turningStateChangedEvent) = 0;
	};
}
#endif