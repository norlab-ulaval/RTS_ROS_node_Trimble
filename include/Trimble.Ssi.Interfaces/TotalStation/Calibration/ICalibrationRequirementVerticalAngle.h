#ifndef ICALIBRATIONREQUIREMENTVERTICALANGLE_H
#define ICALIBRATIONREQUIREMENTVERTICALANGLE_H
#include "Calibration/ICalibrationRequirement.h"

namespace SSI
{
	class ICalibrationRequirementVerticalAngle :public ICalibrationRequirement
	{
	public:
		virtual ~ICalibrationRequirementVerticalAngle();

		/**
		 * Gets the minimal vertical angle in radiant.
		 * @return The vertical angle minimum.
		 */
		virtual double getVerticalAngleMin() = 0;

		/**
		 * Gets the maximal vertical angle in radiant.
		 * @return The vertical angle maximum.
		 */
		virtual double getVerticalAngleMax() = 0;
	};
}

#endif // ICALIBRATIONREQUIREMENTVERTICALANGLE_H
