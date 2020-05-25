#ifndef ICALIBRATIONSTEP_H_
#define ICALIBRATIONSTEP_H_

#include "CalibrationState.h"
#include "CalibrationStepType.h"
#include "ICalibrationStateChangedListener.h"
#include "ICalibrationProgressListener.h"
#include <vector>
#include "ICalibrationParameter.h"

namespace SSI
{
	/**
	* A step which is performed during a calibration.
	*/
	class ICalibrationStep
	{
	public:
		virtual ~ICalibrationStep();

		/**
		* Register a listener for listening.
		* @param listener to listen
		*/
		virtual void addCalibrationStateChangedListener(ICalibrationStateChangedListener& listener) = 0;

		/**
		* Unsubscribe a listener from listening.
		* @param listener to listen
		*/
		virtual void removeCalibrationStateChangedListener(ICalibrationStateChangedListener& listener) = 0;

		/**
		* register a listener for listening.
		* @param ICalibrationProgressListener to listen
		*/
		virtual void addCalibrationProgressListener(ICalibrationProgressListener& listener) = 0;

		/**
		* unsubscribe a listener from listening.
		* @param ICalibrationProgressListener to listen
		*/
		virtual void removeCalibrationProgressListener(ICalibrationProgressListener& listener) = 0;

		/**
		* Gets the state.
		* @return The state.
		*/
		virtual CalibrationState getState() const = 0;

		/**
		* Sets the state.
		* @param state The state.
		*/
		virtual void setState(CalibrationState state) = 0;

		/**
		* Gets the type.
		* @return The type.
		*/
		virtual CalibrationStepType getType() const = 0;

		/**
		* Runs the calibration step action.
		*/
		virtual void runAction(std::vector<ICalibrationParameter*> parameters) = 0;

		/**
		* Prepares for the calibration step.
		*/
		virtual void prepare() = 0;

		/**
		* Reset step.
		*/
		virtual void reset() = 0;

		/**
		* Confirm step.
		*/
		virtual void confirm() = 0;

		/**
		* Cancel step.
		*/
		virtual void cancel() = 0;

		/**
		* Check whether the step is confirmed.
		* @return true if confirmed.
		*/
		virtual bool isConfirmed() = 0;

		/**
		* Check whether the step is canceled.
		* @return true if canceled
		*/
		virtual bool isCanceled() = 0;

		/**
		* Checks whether progress update is supported
		* @return true if progress updates is supported.
		*/
		virtual bool isProgressUpdateSupported() const = 0;
	};
}
#endif
