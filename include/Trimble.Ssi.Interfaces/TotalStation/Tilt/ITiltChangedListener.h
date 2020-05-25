#ifndef ITILTCHANGEDLISTENER_H_
#define ITILTCHANGEDLISTENER_H_

#include "TiltChangedEvent.h"

namespace SSI
{
	/**
	* listens for tilt changes.
	*/
	class ITiltChangedListener
	{
	public:
		virtual ~ITiltChangedListener();
	
		/**
		* the tilt changed event occurred.
		* @param TiltChangedEvent the event
		*/
		virtual void tiltChanged(const TiltChangedEvent& tiltChangedEvent) = 0;
	};
}
#endif