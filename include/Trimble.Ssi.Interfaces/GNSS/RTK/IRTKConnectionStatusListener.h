#ifndef IRTKCONNECTIONSTATUSLISTENER_H_
#define IRTKCONNECTIONSTATUSLISTENER_H_

#include "RTKConnectionStatusUpdate.h"

namespace SSI
{
	/**
	* Listens for changed RTK correction data source connection status.
	*/
	class IRTKConnectionStatusListener
	{
	public:
		virtual ~IRTKConnectionStatusListener();
	
		/**
		* receives the event message when changes occur.
		* @param NtripConnectionStatusUpdate that occurred
		*/
		virtual void onConnectionStateChanged(const RTKConnectionStatusUpdate& ntripConnectionStatusUpdate) = 0;
	};
}
#endif