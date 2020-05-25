#ifndef ITILTCOMPENSATORCALIBRATION_H_
#define ITILTCOMPENSATORCALIBRATION_H_

#include "Calibration/ICalibrationContainer.h"

namespace SSI
{
	/**
	* The compensator calibration
	*/
	class ITiltCompensatorCalibration : public virtual ICalibrationContainer
	{
	public:
		virtual ~ITiltCompensatorCalibration();
	};
}
#endif
