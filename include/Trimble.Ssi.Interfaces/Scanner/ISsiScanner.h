#ifndef ISSISCANNER_H
#define ISSISCANNER_H
#include "ISsiInterface.h"
#include "IScanProgressListener.h"
#include "IScanDataListener.h"
#include "IScanStateListener.h"
#include "IScanParameter.h"

namespace SSI
{
	/**
	 * This interface provides access to a sensor's basic laser scanning functionality. It is able
	 * to start and stop a scan. It allows also to suspend and resume a scan without resending the
	 * parameters and without specifying where the scan was interrupted.
	 */
	class ISsiScanner :public ISsiInterface
	{
	public:
		virtual ~ISsiScanner();

		/**
		* register a listener for listening.
		* @param listener to listen
		*/
		virtual void addScanDataListener(IScanDataListener & listener) = 0;

		/**
		* unsubscribe a listener from listening.
		* @param listener to listen
		*/
		virtual void removeScanDataListener(IScanDataListener& listener) = 0;

		/**
		* register a listener for listening.
		* @param listener to listen
		*/
		virtual void addScanProgressListener(IScanProgressListener & listener) = 0;

		/**
		* unsubscribe a listener from listening.
		* @param listener to listen
		*/
		virtual void removeScanProgressListener(IScanProgressListener& listener) = 0;

		/**
		* register a listener for listening.
		* @param listener to listen
		*/
		virtual void addScanStateListener(IScanStateListener & listener) = 0;

		/**
		* unsubscribe a listener from listening.
		* @param listener to listen
		*/
		virtual void removeScanStateListener(IScanStateListener& listener) = 0;

		/**
		 * Gets the state of the scanning.
		 * @return The state of the scanning.
		 */
		virtual  ScanState getScanningState() =0;

		/**
		* Starts a scan.
		* @param scanParameter The scan parameter. Use @see CreateScanParameter to
		* retrieve an instance of this object.
		* @remark Fails and returns busy when a scan task is in progress. Successfully cancel and starts over a
		* suspended scan with new scan parameters. On every update a @see ScanDataUpate is
		* fired. At the end a @see ScanProgressUpdate is fired.
		*/
		virtual  void startScan(IScanParameter& scanParameter) = 0;

		/**
		* Stops a scan in progress.
		* @remark Fails and returns not-busy when a there is no scan in progress. An event is fired when the
		* scan is stopped.
		*/
		virtual  void stopScan() = 0;

		/**
		* Suspends a scan in progress.
		* @remark Fails and returns not-busy when a there is no scan in progress or when a scan is already
		*         suspended. An event is fired when the scan is suspended.
		*/
		virtual void suspendScan() =0;

		/**
		* Resumes a suspended scan. Can also be called after a unexpected end of scan.
		* @remarks Fails and returns busy when a scan task is in progress. Fails and return not-busy when there
		*		   is no suspended scan. A @see ScanProgress event is fired when the scan is
		*          complete. The concrete class remembers:
		*          - the scan parameters
		*          - the last received scanned points position
		*          A new call to StartScan will reset the suspended scan.
		*/
		virtual void resumeScan() =0;

		/**
		* Creates a scan parameter object. An instrument will probably implement only one type of scan
		* parameter.
		* @return A scan parameter object.
		*/
		virtual IScanParameter * createScanParameter() =0;
	};
}

#endif // ISSISCANNER_H
