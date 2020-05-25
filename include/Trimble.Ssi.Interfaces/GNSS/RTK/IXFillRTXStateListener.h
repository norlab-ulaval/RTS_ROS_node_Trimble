#ifndef IXFILLRTXSTATELISTENER_H_
#define IXFILLRTXSTATELISTENER_H_

#include "XFillRTXStateUpdate.h"

namespace SSI
{
	/**
	* Listens for changed XFillRTX state.
	*/
	class IXFillRTXStateListener
	{
	public:
		virtual ~IXFillRTXStateListener();

		/**
		* receives the event message when changes occur.
		* @param XFillRTXStateUpdate that occurred
		*/
		virtual void onXFillRTXStateChanged(const XFillRTXStateUpdate& xfillStateUpdate) = 0;
	};
}
#endif