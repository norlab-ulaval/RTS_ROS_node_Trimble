#ifndef ELECTRONICBUBBLESTATE_H
#define ELECTRONICBUBBLESTATE_H

namespace SSI
{
	/**
	* Represents the state of the electronic bubble values
	*/
	enum ElectronicBubbleState
	{
		/**
		* Electronic Bubble values are Ok.
		*/
		EBS_Ok,

		/**
		* Tilt needs calibration.
		*/
		EBS_NeedsCalibration,

		/**
		* Tilt calibration age has expired
		*/
		EBS_CalibrationExpired
	};
}
#endif