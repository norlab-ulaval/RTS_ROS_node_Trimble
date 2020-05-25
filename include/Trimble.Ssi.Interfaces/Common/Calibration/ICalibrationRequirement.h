#ifndef ICALIBRATIONREQUIREMENT_H
#define ICALIBRATIONREQUIREMENT_H
#include "CalibrationRequirementType.h"

namespace SSI
{
	class ICalibrationRequirement
	{
	public:
		virtual ~ICalibrationRequirement();
		/**
		 * Gets the type.
		 * @return The type.
		 */
		virtual CalibrationRequirementType getType() =0;
	};
}

#endif // ICALIBRATIONREQUIREMENT_H
