#ifndef CALIBRATIONAGEINFORMATION_H
#define CALIBRATIONAGEINFORMATION_H

namespace SSI
{
	/**
	* Represents Calibration age.
	*/
	class CalibrationAgeInformation
	{
	public:
		/**
		* Initializes a new instance of the @see CalibrationAgeInformation class.
		*/
		CalibrationAgeInformation(long long lastCalibration, int calibrationAgeLimit);

		/**
		* Initializes a new instance of the @see CalibrationAgeInformation class.
		*/
		CalibrationAgeInformation(const CalibrationAgeInformation &src);
		CalibrationAgeInformation& operator=(const CalibrationAgeInformation& assignMe);

		/**
		* Gets the time of the last calibration.
		* @return The time of the last calibration.
		*/
		long long getLastCalibration();

		/**
		* Gets the calibration age limit.
		* @return The calibration age limit.
		*/
		int getCalibrationAgeLimit();
	private:
		long long _lastCalibration;
		int _calibrationAgeLimit;
	};
}
#endif