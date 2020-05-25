#ifndef IFOCUSSTATECHANGEDLISTENER_H_
#define IFOCUSSTATECHANGEDLISTENER_H_

#include "FocusStateChangedEvent.h"

namespace SSI
{
	/**
	* listens for focus state changes.
	*/
	class IFocusStateChangedListener
	{
	public:
		virtual ~IFocusStateChangedListener();
	
		/**
		* process the occurred event
		* @param the event
		*/
		virtual void focusStateChanged(const FocusStateChangedEvent& event) = 0;
	};
}
#endif