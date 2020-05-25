#ifndef ICALIBRATIONSTEPMANUAL_H_
#define ICALIBRATIONSTEPMANUAL_H_

#include "ICalibrationStep.h"
#include "ManualAction.h"

namespace SSI
{
	/**
	* A calibration step which is meant to be performed by the user.
	*/
	class ICalibrationStepManual : public virtual ICalibrationStep
	{
	public:
		virtual ~ICalibrationStepManual();

		/**
		* Gets the manual action.
		* @return The manual action.
		*/
		virtual ManualAction getManualAction() const = 0;
	};
}
#endif
