#ifndef CALIBRATIONRESULTSEVENT_H_
#define CALIBRATIONRESULTSEVENT_H_

#include "ICalibrationResult.h"
#include "CalibrationResultType.h"
#include <vector>

namespace SSI
{
	/**
	* Represents event for incoming calibration result events.
	*/
	class CalibrationResultsEvent
	{
	public:
		/**
		* Initializes a new instance of the <see cref="CalibrationResultsEvent"/> class.
		* @param results The results.
		*/
		CalibrationResultsEvent(std::vector<ICalibrationResult*> results);

		/**
		* Uninitializes a instance of the <see cref="CalibrationResultsEvent"/> class.
		*/
		virtual ~CalibrationResultsEvent();

		/**
		* Get the cancel flag
		* @return <c>true</c> if cancelation is requested; otherwise, <c>false</c>.
		*/
		bool getCancel() const;

		/**
		* Set this flag to cancel the calibration when the calibration results do not match your expectations
		* @param cancel <c>true</c> if cancelation is requested; otherwise, <c>false</c>.
		*/
		void setCancel(bool cancel);

		/**
		* Determines whether an calibration result of the specified type exists.
		* @param  type The type.
		* @return true if it has a calibration result, otherwise false
		*/
		bool hasCalibrationResult(CalibrationResultType type) const;

		/**
		* Gets the calibration result of the specified type.
		* @param type The type.
		* @return The calibration result of the specified type.
		*/
		ICalibrationResult& getCalibrationResult(CalibrationResultType type) const;
	private:
		std::vector<ICalibrationResult*> _results; //< the results
		bool _cancel; //< cancel flag
	};
}
#endif
