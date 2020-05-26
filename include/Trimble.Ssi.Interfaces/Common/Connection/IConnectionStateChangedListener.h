#ifndef CONNECTIONSTATECHANGEDLISTENER_H_
#define CONNECTIONSTATECHANGEDLISTENER_H_

#include "ConnectionState.h"

namespace Common
{
	/**
	* Listens to connection changes
	*/
	class IConnectionStateChangedListener
	{
	public:
		virtual ~IConnectionStateChangedListener();

		/**
		* Callback for the connection state changed call.
		* @param ConnectionState state of the connection
		*/
		virtual void onConnectionStateChanged(ConnectionState state) = 0;
	};
}
#endif
