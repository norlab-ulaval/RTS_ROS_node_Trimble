#ifndef AUTOMATICACTION_H_
#define AUTOMATICACTION_H_

namespace SSI
{
	/**
	* Represents an action that can be run automatically by the sensor
	*/
	enum AutomaticAction
	{
		AA_ChangeFace,		/**< Represents a change face operation, performed by the sensor */
		AA_Measure,			/**< Represents a measure operation, performed by the sensor */
		AA_AimToTarget,		/**< Represents an operation where the sensor automatically focuses the target */
		AA_CalibrateTilt,	/**< Represents a tilt calibration, performed by the sensor */
		AA_Initiate			/**< Represents a initialization step, performed by the sensor */
	};
}
#endif
