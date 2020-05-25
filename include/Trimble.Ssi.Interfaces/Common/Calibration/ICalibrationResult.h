#ifndef ICALIBRATIONRESULT_H_
#define ICALIBRATIONRESULT_H_

#include "CalibrationResultType.h"

namespace SSI
{
	/**
	* Represents a result of a calibration
	*/
	class ICalibrationResult
	{
	public:
		virtual ~ICalibrationResult();

		/**
		* Gets the type of the calibration result.
		* @return The type of the calibration result.
		*/
		virtual CalibrationResultType getCalibrationResultType() const = 0;
	};
}
#endif