#ifndef ICALIBRATIONRESULTCOLLIMATIONERROR_H_
#define ICALIBRATIONRESULTCOLLIMATIONERROR_H_

#include "Calibration/ICalibrationResult.h"
#include "Corrections/ICollimationError.h"

namespace SSI
{
	class ICalibrationResultCollimationError : public ICalibrationResult
	{
	public:
		virtual ~ICalibrationResultCollimationError();
		virtual ICollimationError* getCollimationError() const  = 0;
	};
}
#endif
