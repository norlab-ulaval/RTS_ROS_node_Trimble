#ifndef CORRECTIONVALUETYPE_H_
#define CORRECTIONVALUETYPE_H_

namespace SSI
{
	/**
	*   all possible correction value types
	*/
	enum CorrectionValueType
	{
		IT_OpticalCollimation,						/** Optical Collimation */
		IT_TrunnionAxisError,						/** Trunnion Axis */
		IT_TrackerCollimation,						/** Tracker Collimation */
		IT_GreenHighPowerLaserCollimationError,		/** Green High Power Laser Collimation */
		IT_TiltOffset,								/** Tilt Offset */
	};
}
#endif
