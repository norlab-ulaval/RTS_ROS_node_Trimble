#ifndef ISCANDATALISTENER_H
#define ISCANDATALISTENER_H
#include "ScanDataUpdate.h"

namespace SSI
{
	/**
	* Listens for scan data.
	*/
	class IScanDataListener
	{

	public:
		virtual ~IScanDataListener();
		/**
		* receives the scan data updates.
		* @param scanDataUpdate that scan data
		*/
		virtual void onScanDataUpdate(ScanDataUpdate & scanDataUpdate) = 0;
	};
}
#endif // ISCANDATALISTENER_H
