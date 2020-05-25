#ifndef CALIBRATIONSTATECHANGEDLISTENER_H_
#define CALIBRATIONSTATECHANGEDLISTENER_H_

#include "CalibrationStateChangedEvent.h"

namespace SSI
{
	/**
	* listens for calibration state changes.
	*/
	class ICalibrationStateChangedListener
	{
	public:
		virtual ~ICalibrationStateChangedListener();

		/**
		* process the occurred event
		* @param event the event
		*/
		virtual void calibrationStateChanged(const CalibrationStateChangedEvent& event) = 0;
	};
}
#endif