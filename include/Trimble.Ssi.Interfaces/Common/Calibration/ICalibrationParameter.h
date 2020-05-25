#ifndef ICALIBRATIONPARAMETER_H_
#define ICALIBRATIONPARAMETER_H_

#include "CalibrationParameterType.h"

namespace SSI
{
	/**
	* Represents a Parameter of a calibration
	*/
	class ICalibrationParameter
	{
	public:
		virtual ~ICalibrationParameter();

		/**
		* Gets the type of the calibration Parameter.
		* @return The type of the calibration Parameter.
		*/
		virtual CalibrationParameterType getCalibrationParameterType() const = 0;
	};
}
#endif