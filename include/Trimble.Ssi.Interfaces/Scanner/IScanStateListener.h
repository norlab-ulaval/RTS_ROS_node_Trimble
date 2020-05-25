#ifndef ISCANSTATELISTENER_H
#define ISCANSTATELISTENER_H
#include "ScanStateUpdate.h"

namespace SSI
{
	/**
	* Listens for scan state changes.
	*/
	class IScanStateListener
	{
	public:
		virtual ~IScanStateListener();

		/**
		* receives the scan state change updates.
		* @param scanStateUpdate that occurred
		*/
		virtual void onScanStateChange(ScanStateUpdate & scanStateUpdate) = 0;
	};
}

#endif // ISCANSTATELISTENER_H
