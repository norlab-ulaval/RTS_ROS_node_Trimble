#ifndef CALIBRATIONSTEPTYPE_H_
#define CALIBRATIONSTEPTYPE_H_

namespace SSI
{
	/**
	* Represents the type of a calibration step
	*/
	enum CalibrationStepType
	{
		CST_Manual,		/**< The type of a calibration step, which is meant to be performed by the user */
		CST_Automatic,	/**< The type of a calibration step, which will be performed by the sensor */
		CST_Result		/**< The type of a calibration step, which displays calibration results */
	};
}
#endif