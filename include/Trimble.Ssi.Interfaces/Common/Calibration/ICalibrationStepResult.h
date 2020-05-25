#ifndef ICALIBRATIONSTEPRESULT_H_
#define ICALIBRATIONSTEPRESULT_H_

#include "ICalibrationResult.h"
#include "ICalibrationStep.h"
#include <vector>

namespace SSI
{
	/**
	* A calibration step which carries the calibration result.
	*/
	class ICalibrationStepResult : public virtual ICalibrationStep
	{
	public:
		virtual ~ICalibrationStepResult();

		/**
		* Determines whether an calibration result of the specified type exists.
		* @param type The type.
		* @return true if a calibration result exists,otherwise false
		*/
		virtual bool hasCalibrationResult(CalibrationResultType type) const = 0;

		/**
		* Gets the calibration result of the specified type.
		* @param type The type.
		* @returns The calibration result of the specified type.
		*/
		virtual ICalibrationResult& getCalibrationResult(CalibrationResultType type) const = 0;

		/**
		* Gets the calibration results.
		* @returns The calibration results as a vector.
		*/
		virtual std::vector<ICalibrationResult*> getCalibrationResults() const = 0;
	};
}
#endif
