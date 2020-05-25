#ifndef ITRUNNIONAXISERRORCALIBRATION_H_
#define ITRUNNIONAXISERRORCALIBRATION_H_

#include "Calibration/ICalibrationContainer.h"

namespace SSI
{
	/**
	* The trunnion axis error calibration
	*/
	class ITrunnionAxisErrorCalibration : public virtual ICalibrationContainer
	{
	public:
		virtual ~ITrunnionAxisErrorCalibration();
	};
}
#endif