#ifndef TILTSENSORCALIBRATIONSTATE_H_
#define TILTSENSORCALIBRATIONSTATE_H_

namespace SSI
{
	/**
	* Represents the calibration state of the tilt sensors
	*/
	enum TiltSensorCalibrationState
	{
		/**
		* All tilt sensors are calibrated
		*/
		TSC_Calibrated,

		/**
		* @see CalibrationType.TiltSensorCalibration is needed
		*/
		TSC_NeedsTiltCalibration,

		/**
		* @see CalibrationType.MagnetometerCalibration is needed
		*/
		TSC_NeedsMagnetometerCalibration,

		/**
		* @see CalibrationType.MagnetometerAlignment is needed
		*/
		TSC_NeedsMagnetometerAllignment,

		/**
		* Calibration has expired
		*/
		TSC_CalibrationExpired
	};
}
#endif