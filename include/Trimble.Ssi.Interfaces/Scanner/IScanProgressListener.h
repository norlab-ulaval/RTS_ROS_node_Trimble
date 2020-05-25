#ifndef ISCANPROGRESSLISTENER_H
#define ISCANPROGRESSLISTENER_H
#include "ScanProgressUpdate.h"
namespace SSI
{

	/**
	* Listens for scan progress.
	*/
	class IScanProgressListener
	{
	public:
		virtual ~IScanProgressListener();

		/**
		* receives the scan progress updates.
		* @param scanProgressUpdate that occurred
		*/
		virtual  void onScanProgress(ScanProgressUpdate &scanProgressUpdate) = 0;
	};
}

#endif // ISCANPROGRESSLISTENER_H
