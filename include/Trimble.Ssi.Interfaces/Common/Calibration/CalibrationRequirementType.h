#ifndef CALIBRATIONREQUIREMENTTYPE_H
#define CALIBRATIONREQUIREMENTTYPE_H

namespace SSI
{
	enum CalibrationRequirementType
	{
		/**
		 *  Represents the type of a requirement to define the minimum and maximum allowed vertical angles of the calibration in radiant
		 */
		CalibrationRequirement_VertialAngle,

		/**
		 * Represents the type of a requirement to define the minimum and maximum allowed slope distance of the calibration in meter
		 */
		CalibrationRequirement_SlopeDistance
	};
}

#endif // CALIBRATIONREQUIREMENTTYPE_H
