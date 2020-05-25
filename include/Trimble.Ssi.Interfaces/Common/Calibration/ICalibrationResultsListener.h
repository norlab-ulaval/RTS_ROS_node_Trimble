#ifndef CALIBRATIONRESULTSLISTENER_H_
#define CALIBRATIONRESULTSLISTENER_H_

#include "CalibrationResultsEvent.h"

namespace SSI
{
	/**
	* Listens for calibration results observations.
	*/
	class ICalibrationResultsListener
	{
	public:
		virtual ~ICalibrationResultsListener();

		/**
		* Process the occurred event.
		* @param event the event
		*/
		virtual void calibrationResults(const CalibrationResultsEvent& event) = 0;
	};
}
#endif