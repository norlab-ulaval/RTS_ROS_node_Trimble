#ifndef CALIBRATESTATE_H_
#define CALIBRATESTATE_H_

namespace SSI
{
	/**
	* Represents the state of <see cref="ICalibrationStep"/>
	*/
	enum CalibrationState
	{
		CS_Idle,			/**< The Idle state, the calibration step is ready to run */
		CS_Prepare,			/**< The repare state, the calibration step is preparing for the action */
		CS_WaitForConfirm,	/**< The Calibration step awaits confirmation or cancelation */
		CS_Canceled,		/**< The Calibration step got canceled */
		CS_Running,			/**< The Calibration step is performing its tasks */
		CS_Complete			/**< The Calibration step is completed */
	};
}
#endif