#ifndef IGREENHIGHPOWERLASERCALIBRATION_H_
#define IGREENHIGHPOWERLASERCALIBRATION_H_
#include "Calibration/ICalibrationContainer.h"

namespace  SSI {
	class IGreenHighPowerLaserCalibration :public virtual ICalibrationContainer
	{
	public:
		virtual ~IGreenHighPowerLaserCalibration();
	};
}
#endif //IGREENHIGHPOWERLASERCALIBRATION_H_