#ifndef ICOLLIMATIONERRORCALIBRATION_H_
#define ICOLLIMATIONERRORCALIBRATION_H_

#include "Calibration/ICalibrationContainer.h"

namespace SSI
{
	/**
	* The collimation error calibration
	*/
	class ICollimationErrorCalibration : public virtual ICalibrationContainer
	{
	public:
		virtual ~ICollimationErrorCalibration();
	};
}
#endif