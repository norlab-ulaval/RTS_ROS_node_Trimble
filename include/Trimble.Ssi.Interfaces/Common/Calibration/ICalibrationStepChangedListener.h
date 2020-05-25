#ifndef CALIBRATIONSTEPCHANGEDLISTENER_H_
#define CALIBRATIONSTEPCHANGEDLISTENER_H_

#include "CalibrationStepChangedEvent.h"

namespace SSI
{
	/**
	* listens for calibration step changes.
	*/
	class ICalibrationStepChangedListener
	{
	public:
		virtual ~ICalibrationStepChangedListener();
		/**
		* process the occurred event
		* @param event the event
		*/
		virtual void calibrationStepChanged(const CalibrationStepChangedEvent& event) = 0;
	};
}
#endif