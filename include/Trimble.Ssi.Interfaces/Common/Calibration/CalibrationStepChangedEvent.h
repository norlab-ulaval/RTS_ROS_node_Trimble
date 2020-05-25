#ifndef CALIBRATIONSTEPCHANGEDEVENT_H_
#define CALIBRATIONSTEPCHANGEDEVENT_H_

#include "ICalibrationStep.h"

namespace SSI
{
	/**
	* Event used whenever the current calibration step changes
	*/
	class CalibrationStepChangedEvent
	{
	public:
		/**
		* Initializes a new instance of the <see cref="CalibrationStepChangedEvent"/> class.
		* @param step The step.
		*/
		CalibrationStepChangedEvent(ICalibrationStep& step);

		/**
		* Uninitializes a instance of the <see cref="CalibrationStepChangedEvent"/> class.
		*/
		virtual ~CalibrationStepChangedEvent();

		/**
		* Gets the step.
		* @return The step.
		*/
		ICalibrationStep& getStep() const;
	private:
		/**
		* Sets the step.
		* @param step The step.
		*/
		void setStep(ICalibrationStep& step);
		ICalibrationStep& _step; /**< the calibration step */
	};
}
#endif
