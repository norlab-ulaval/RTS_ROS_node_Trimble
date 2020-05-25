#ifndef ICALIBRATIONRESULTTRUNNIONAXISERROR_H_
#define ICALIBRATIONRESULTTRUNNIONAXISERROR_H_

#include "Calibration/ICalibrationResult.h"
#include "Corrections/ITrunnionAxisError.h"

namespace SSI
{
	class ICalibrationResultTrunnionAxisError : public ICalibrationResult
	{
	public:
		virtual ~ICalibrationResultTrunnionAxisError();
		virtual ITrunnionAxisError* getTrunnionAxisError() const  = 0;
	};
}
#endif
