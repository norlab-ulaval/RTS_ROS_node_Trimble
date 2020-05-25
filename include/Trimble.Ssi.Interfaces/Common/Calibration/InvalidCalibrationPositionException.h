#ifndef INVALIDCALIBRATIONPOSITIONEXCEPTION_H_
#define INVALIDCALIBRATIONPOSITIONEXCEPTION_H_

#include "Calibration/CalibrationException.h"

namespace SSI
{
	class TSObservationContainer;

	class InvalidCalibrationPositionException : public CalibrationException
	{
	public:
		InvalidCalibrationPositionException(double verticalAngle, double distance, bool isVerticalAngleOutOfRange, bool isDistanceOutOfRange, bool isTargetTooSmall, bool isTargetEnvironmentDisturbed, bool isInternalAccuracyOutOfRange);
		virtual ~InvalidCalibrationPositionException(void) throw ();

		double verticalAngle() const;
		double distance() const;
		bool isVerticalAngleOutOfRange() const;
		bool isDistanceOutOfRange() const;
		bool isTargetTooSmall() const;
		bool isTargetEnvironmentDisturbed() const;
		bool isInternalAccuracyOutOfRange() const;

	private:
		double m_verticalAngle;
		double m_distance;
		bool m_isVerticalAngleOutOfRange;
		bool m_isDistanceOutOfRange;
		bool m_isTargetTooSmall;
		bool m_isTargetEnvironmentDisturbed;
		bool m_isInternalAccuracyOutOfRange;
	};
}
#endif