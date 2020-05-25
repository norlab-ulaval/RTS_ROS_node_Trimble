#ifndef ICALIBRATIONREQUIREMENTSLOPEDISTANCE_H
#define ICALIBRATIONREQUIREMENTSLOPEDISTANCE_H
#include "Calibration/ICalibrationRequirement.h"

namespace SSI
{
	class ICalibrationRequirementSlopeDistance :public ICalibrationRequirement
	{
	public:
		virtual ~ICalibrationRequirementSlopeDistance();

		/**
		 * Gets the minimal slope distance in meter.
		 * @return The slope distance minimum.
		 */
		virtual  double getSlopeDistanceMin() = 0;

		/**
		 * Gets the maximal slope distance in meter.
		 * @return The slope distance maximum.
		 */
		virtual  double getSlopeDistanceMax() = 0;
	};
}

#endif // ICALIBRATIONREQUIREMENTSLOPEDISTANCE_H
