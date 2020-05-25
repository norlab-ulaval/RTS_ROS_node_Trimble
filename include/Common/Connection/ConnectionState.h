#ifndef CONNECTIONSTATE_H_
#define CONNECTIONSTATE_H_

namespace Common
{
	/**
	* Represents a connection state.
	* Use ISensor::ConnectionState to obtain the current state of the connection to an ISensor instance.
	* @see ISensor
	*/
	enum ConnectionState
	{
		CS_CONNECTED,		/**< connection established */
		CS_CONNECTING,		/**< connecting in progress */
		CS_DISCONNECTED,	/**< no connection */
		CS_DISCONNECTING,	/**< disconnecting in progress */
		CS_LINKDOWN,		/**< link is down.  this is likely but not guaranteed to be permanant */ 
        CS_LINKTEMPDOWN     /**< radio link is temporarily down.  from here it either goes to CS_CONNECTED or CS_LINKDOWN*/
	};
}
#endif
