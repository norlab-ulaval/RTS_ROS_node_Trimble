#ifndef IXFILLSTATELISTENER_H_
#define IXFILLSTATELISTENER_H_

#include "XFillStateUpdate.h"

namespace SSI
{
	/**
	* Listens for changed XFill state.
	*/
	class IXFillStateListener
	{
	public:
		virtual ~IXFillStateListener();

		/**
		* receives the event message when changes occur.
		* @param XFillStateUpdate that occurred
		*/
		virtual void onXFillStateChanged(const XFillStateUpdate& xfillStateUpdate) = 0;
	};
}
#endif