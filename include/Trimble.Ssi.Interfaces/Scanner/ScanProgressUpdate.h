#ifndef SCANPROGRESSUPDATE_H
#define SCANPROGRESSUPDATE_H
#include "IScanEstimate.h"

namespace SSI
{
	/**
	 * Provides data for scan progress updates
	 */
	class ScanProgressUpdate
	{
	public:
		/**
		 * Initializes a new instance of the @see ScanProgressUpdate  class.
		 * @param scanEstimate The scan estimate.
		 * @param percentageDone The percentage between 0 and 1.
		 */
		ScanProgressUpdate(IScanEstimate& scanEstimate,double percentageDone);
		virtual ~ScanProgressUpdate();
		/**
		 * Gets the estimate to complate scan.
		 */
		IScanEstimate& getEstimate();

		/**
		 * Gets the percentage of scan done between 0 and 1
		 */
		double getPercentageDone();
	private:
		IScanEstimate& _scanEstimate;
		double _percentageDone;
	};
}

#endif // SCANPROGRESSUPDATE_H
