#ifndef CALIBRATIONRESULTTYPE_H_
#define CALIBRATIONRESULTTYPE_H_

namespace SSI
{
	/**
	* Represents the type of calibration results
	*/
	enum CalibrationResultType
	{
		CRT_CollimationError,  /* The collimation error calibration result */
		CRT_TrunnionAxisError, /* The trunnion axis error calibration result */
		CRT_GreenHighPowerLaserCollimationError /* The green high power laser collimation error*/
	};
}
#endif