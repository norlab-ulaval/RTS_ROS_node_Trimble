#ifndef ICALIBRATIONSTEPAUTOMATIC_H_
#define ICALIBRATIONSTEPAUTOMATIC_H_

#include "ICalibrationStep.h"
#include "AutomaticAction.h"

namespace SSI
{
	/**
	* A calibration step which the instrument will perform.
	*/
	class ICalibrationStepAutomatic : public virtual ICalibrationStep
	{
	public:
		virtual ~ICalibrationStepAutomatic();

		/**
		* Gets the automatic action.
		* The automatic action.
		*/
		virtual AutomaticAction getAutomaticAction() const = 0;
	};
}
#endif
