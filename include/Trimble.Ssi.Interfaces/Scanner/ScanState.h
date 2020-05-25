#ifndef SCANSTATE_H
#define SCANSTATE_H
namespace SSI
{
	/**
	* Possible scan states.
	*/
	enum ScanState
	{
		/**
		* Scanner is in an idle state.
		*/
		ScanState_Idle,

		/**
		* Scanner starts performing a new scan
		*/
		ScanState_Starting,

		/**
		* Scanner is performing a scan
		*/
		ScanState_Running,

		/**
		* Scanner is moving to a paused state
		*/
		ScanState_Suspending,

		/**
		* Scanner pauses an ongoing scan
		*/
		ScanState_Suspended,

		/**
		* Scanner is moving to a running state after being suspended
		*/
		ScanState_Resuming,

		/**
		* Scanner is aborting the scan before completion
		*/
		ScanState_Stopping
	};
}
#endif // SCANSTATE_H
