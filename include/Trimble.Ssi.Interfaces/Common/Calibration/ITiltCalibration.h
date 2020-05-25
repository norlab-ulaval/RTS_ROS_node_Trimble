#ifndef ITILTCALIBRATION_H_
#define ITILTCALIBRATION_H_

#include "Calibration/ICalibrationContainer.h"

namespace SSI
{
	/**
	* The compensator calibration
	*/
	class ITiltCalibration : public virtual ICalibrationContainer
	{
	public:
		virtual ~ITiltCalibration();
	};
}
#endif