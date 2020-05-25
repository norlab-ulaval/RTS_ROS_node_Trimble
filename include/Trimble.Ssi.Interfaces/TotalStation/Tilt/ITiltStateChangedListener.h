#ifndef ITILTSTATECHANGEDLISTENER_H_
#define ITILTSTATECHANGEDLISTENER_H_

#include "TiltStateChangedEvent.h"

namespace SSI
{
	/**
	* listens for tilt state changes.
	*/
	class ITiltStateChangedListener
	{
	public:
		virtual ~ITiltStateChangedListener();
	
		/**
		* a tilt state changed event occurred.
		* @param tiltStateChangedEvent the event
		*/
		virtual void tiltStateChanged(const TiltStateChangedEvent& tiltStateChangedEvent) = 0;
	};
}
#endif