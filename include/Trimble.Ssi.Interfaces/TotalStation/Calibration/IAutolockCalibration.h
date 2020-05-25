#ifndef IAUTOLOCKCALIBRATION_H_
#define IAUTOLOCKCALIBRATION_H_

#include "Calibration/ICalibrationContainer.h"

namespace SSI
{
	/**
	* The autolock calibration
	*/
	class IAutolockCalibration : public virtual ICalibrationContainer
	{
	public:
		virtual ~IAutolockCalibration();
	};
}
#endif