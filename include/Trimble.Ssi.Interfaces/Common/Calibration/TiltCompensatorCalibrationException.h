#ifndef TILTCOMPENSATORCALIBRATIONEXCEPTION_H_
#define TILTCOMPENSATORCALIBRATIONEXCEPTION_H_

#include "Calibration/CalibrationException.h"

namespace SSI
{
	class TiltCompensatorCalibrationException : public CalibrationException
	{
	public:
		TiltCompensatorCalibrationException(bool servoTurnFailed, bool isTiltOutOfRange, bool isTiltNotStable);
		~TiltCompensatorCalibrationException(void) throw ();

		bool servoTurnFailed() const;
		bool isTiltOutOfRange() const;
		bool isTiltNotStable() const;
	private:
		bool m_ServoTurnFailed;
		bool m_IsTiltOutOfRange;
		bool m_IsTiltNotStable;
	};
}
#endif