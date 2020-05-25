#ifndef SENSORNEEDSCALIBRATIONEXCEPTION_H_
#define SENSORNEEDSCALIBRATIONEXCEPTION_H_

#include "SsiException.h"

namespace SSI
{
	/**
	* The sensor needs calibration exception.
	*/
	class SensorNeedsCalibrationException : public SsiException
	{
	public:
		/**
		* constructor.
		* @param operationDescription exception causing operation
		* @param errorCode error code
		*/
		SensorNeedsCalibrationException(const char* operationDescription, const int errorCode);
		SensorNeedsCalibrationException(const SensorNeedsCalibrationException& copyMe);
		SensorNeedsCalibrationException(const char * operationDescription,const char* message, int errorCode);
	private:
		SensorNeedsCalibrationException();
		SensorNeedsCalibrationException& operator=(const SensorNeedsCalibrationException&);
	};
}
#endif