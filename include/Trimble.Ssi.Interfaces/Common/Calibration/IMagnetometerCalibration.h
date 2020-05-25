#ifndef IMAGNETOMETERCALIBRATION_H_
#define IMAGNETOMETERCALIBRATION_H_

#include "Calibration/ICalibrationContainer.h"

namespace SSI
{
	class IMagnetometerCalibration : public virtual ICalibrationContainer
	{
	public:
		virtual ~IMagnetometerCalibration();
	};
}
#endif