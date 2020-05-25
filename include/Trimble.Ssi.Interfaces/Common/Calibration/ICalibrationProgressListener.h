#ifndef ICALIBRATIONPROGRESSLISTENER_H_
#define ICALIBRATIONPROGRESSLISTENER_H_

#include "CalibrationProgress.h"

namespace SSI
{
	class ICalibrationProgressListener
	{
	public:
		virtual ~ICalibrationProgressListener();

		/**
		* receives the event message when changes occur.
		* @param FileImportProgress that occurred
		*/
		virtual void onCalibrationProgressUpdate(const CalibrationProgress& calibrationProgress) = 0;
	};
}
#endif