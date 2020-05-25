#ifndef CALIBRATIONTYPE_H_
#define CALIBRATIONTYPE_H_

namespace SSI
{
	/**
	* Represents the Type of a calibration
	*/
	enum CalibrationType
	{
		CT_CompensatorCalibration,			/**< Represents the type of a Compensator calibration */
		CT_AutolockCalibration,				/**< Represents the type of a Autolock calibration */
		CT_AutolockAutomaticCalibration,	/**< Represents the type of a automatic Autolock calibration */
		CT_CollimationErrorCalibration,		/**< Represents the type of a collimation error calibration */
		CT_TrunnionAxisErrorCalibration,	/**< Represents the type of a trunnion axis error calibration */
		CT_GreenHighPowerLaserCalibration,	/**< Represents the type of a green high power laser calibration */
		CT_TiltSensorCalibration,			/**< Represents the type of a Tilt calibration */
		CT_MagnetometerCalibration,			/**< Represents the type of a Magnetometer calibration */
		CT_MagnetometerAllignment,			/**< Represents the type of a Magnetometer allignment calibration */
		CT_None
	};
}
#endif
