#ifndef SCANSTATEUPDATE_H
#define SCANSTATEUPDATE_H
#include "ScanState.h"

namespace SSI
{
	/**
	* Provides data for scan state change update
	*/
	class ScanStateUpdate
	{
	public:
		/**
		 * Initializes a new instance of the @see ScanStateUpdate  class.
		 * @param scanSate the scan state
		 */
		ScanStateUpdate(ScanState scanSate);
		virtual ~ScanStateUpdate();
		/**
		 * Gets scan state
		 * @return the scan state
		 */
		ScanState getScanState();
	private:
		ScanState _scanState;
	};
}

#endif // SCANSTATEUPDATE_H
