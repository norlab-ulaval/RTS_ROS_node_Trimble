#ifndef RTXINITIALIZATIONSTATE_H_
#define RTXINITIALIZATIONSTATE_H_

namespace SSI
{
	/**
	* Represents the state of the RTX position initialization.
	* @see ISsiRTXQuickStartBet
	*/
	enum RTXInitializationState
	{
		/**
		* RTX position is currently not initializable.
		*/
		RIS_NotInitializable,

		/**
		* RTX position can be initialized.
		*/
		RIS_Initializable,

		/**
		* RTX position initialization is running.
		*/
		RIS_Initializing,

		/**
		* RTX position has been initialized.
		*/
		RIS_Initialized
	};
}
#endif