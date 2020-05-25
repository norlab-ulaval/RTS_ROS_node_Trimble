#ifndef DISCONNECTMODE_H
#define DISCONNECTMODE_H

namespace SSI
{
	/**
	* This enumeration represents the modes after disconnecting from the instrument
	*/
	enum DisconnectMode
	{
		/**
		* The instrument stays in an idle state
		*/
		DM_KeepRunning,

		/**
		* The instrument restarts and gets back to an idle state
		*/
		DM_Restart,

		/**
		* The instrument shuts down
		*/
		DM_ShutDown,
        
        /**
         * The instrument applies the startupMode changes, this could drop the connection, the instrument is waiting for a reconnection
         */
        DM_RestartCommunication,
	};
}
#endif