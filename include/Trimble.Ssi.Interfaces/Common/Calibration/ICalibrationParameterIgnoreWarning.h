#ifndef ICALIBRATIONPARAMETERIGNOREWARNING_H_
#define ICALIBRATIONPARAMETERIGNOREWARNING_H_

#include "CalibrationParameterType.h"
#include "ICalibrationParameter.h"

namespace SSI
{
	/**
	* Represents a parameter that defines if warnings should be ignored during the calibration
	*/
	class ICalibrationParameterIgnoreWarning : public ICalibrationParameter
	{
	public:
		virtual ~ICalibrationParameterIgnoreWarning();

		/**
		* Gets the type of the calibration parameter.
		* @return The type of the calibration parameter.
		*/
		virtual CalibrationParameterType getCalibrationParameterType() const = 0;

		/**
		* Gets the information if warnings should be ignored during calibration.
		* @return The information if warnings should be ignored during calibration.
		*/
		virtual bool getIgnore() const = 0;

		/**
		* Sets the information if warnings should be ignored during calibration.
		* @param ignore The information if warnings should be ignored during calibration.
		*/
		virtual void setIgnore(bool ignore) = 0;
	};
}
#endif