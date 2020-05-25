#ifndef IMAGNETOMETERALLIGNMENT_H_
#define IMAGNETOMETERALLIGNMENT_H_

#include "Calibration/ICalibrationContainer.h"

namespace SSI
{
	class IMagnetometerAlignment : public virtual ICalibrationContainer
	{
	public:
		virtual ~IMagnetometerAlignment();
	};
}
#endif