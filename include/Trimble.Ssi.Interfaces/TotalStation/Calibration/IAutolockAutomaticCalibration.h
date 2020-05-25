#ifndef IAUTOLOCKAUTOMATICCALIBRATION_H_
#define IAUTOLOCKAUTOMATICCALIBRATION_H_

#include "Calibration/ICalibrationContainer.h"

namespace SSI
{
	/**
	* The automatic autolock calibration template.
	*/
	class IAutolockAutomaticCalibration : public virtual ICalibrationContainer
	{
	public:
		virtual ~IAutolockAutomaticCalibration();
	};
}
#endif