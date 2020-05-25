#ifndef CALIBRATIONRESULTEXCEPTION_H_
#define CALIBRATIONRESULTEXCEPTION_H_

#include "Calibration/CalibrationException.h"

namespace SSI
{
	class CalibrationResultException : public CalibrationException
	{
	public:
		CalibrationResultException(void);
		virtual ~CalibrationResultException(void) throw ();
	};
}
#endif