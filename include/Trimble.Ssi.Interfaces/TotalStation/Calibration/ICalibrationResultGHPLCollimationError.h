#ifndef ICALIBRATIONRESULTGHPLCOLLIMATIONERROR_H_
#define ICALIBRATIONRESULTGHPLCOLLIMATIONERROR_H_

#include "Calibration/ICalibrationResult.h"
#include "Corrections/IGreenHighPowerLaserCollimationError.h"

namespace SSI
{
	class ICalibrationResultGHPLCollimationError : public ICalibrationResult
	{
	public:
		virtual ~ICalibrationResultGHPLCollimationError();
		virtual IGreenHighPowerLaserCollimationError* getGHPLCollimationError() const  = 0;
	};
}
#endif
