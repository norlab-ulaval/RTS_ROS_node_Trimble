#ifndef ICALIBRATIONCONTAINER_H_
#define ICALIBRATIONCONTAINER_H_

#include "ICalibrationStep.h"
#include "CalibrationType.h"
#include "ICalibrationStepChangedListener.h"
#include <vector>
#include "../../TotalStation/Calibration/ICalibrationRequirementVerticalAngle.h"
#include "ICalibrationParameter.h"

namespace SSI
{
	/**
	* Represents a container of Calibration steps.
	*/
	class ICalibrationContainer
	{
	public:
		virtual ~ICalibrationContainer();

		/**
		* get the calibration steps.
		* @return Steps for the calibration
		*/
		virtual std::vector<ICalibrationStep*> getSteps() const=0;

		/**
		* set the calibration steps.
		* @param steps for the calibration
		*/
		virtual void setSteps(std::vector<ICalibrationStep*> steps)=0;

		/**
		* Register a listener for listening.
		* @param listener to listen
		*/
		virtual void addCalibrationStepChangedListener(ICalibrationStepChangedListener& listener)=0;

		/**
		* Unsubscribe a listener from listening.
		* @param listener to listen
		*/
		virtual void removeCalibrationStepChangedListener(ICalibrationStepChangedListener& listener)=0;

		/**
		* Gets the type of the calibration container.
		* @return The type of the calibration container.
		*/
		virtual CalibrationType getType()=0;

		/**
		*  Runs the calibration. The thread blocks if not all Calibration steps are confirmed.
		*/
		virtual void runCalibrationBlocking(std::vector<ICalibrationParameter*> parameters) = 0;

		/**
		* Called when the calibration step changes.
		* update all observers about the next step.
		* @param step The step.
		*/
		virtual void onCalibrationStepChanged(ICalibrationStep& step)=0;

		/**
		* Creates the parameter associated with the specified <paramref name="parameterType"/>.
		* @param parameterType Type of the parameter.
		* @return An instance of the <see cref="ICalibrationParameter"/> interface, associated with the specified <paramref name="parameterType"/>.
		*/
		virtual ICalibrationParameter* createParameter(CalibrationParameterType parameterType) = 0;

		/**
		 * Lists the supported parameter types.
		 * @return Enumeration of supported calibration parameter types
		 */
		virtual  std::vector<CalibrationParameterType> listSupportedCalibrationParameterTypes() = 0;

		/**
		* Check if a calibration parameter type is supported.
		* @return true if it is supported, otherwise false
		*/
		virtual bool isSupported(CalibrationParameterType type) = 0;

		/**
		 * Gets the Calibration Requirement.
		 * @return An instance of @see ICalibrationRequirement with the requested type.
		 */
		virtual  ICalibrationRequirement& getCalibrationRequirement(CalibrationRequirementType type) = 0;

		/**
		* Lists the supported Requirement types.
		* @return Enumeration of supported calibration requirement types
		*/
		virtual  std::vector<CalibrationRequirementType> listSupportedCalibrationRequirementTypes() = 0;
	};
}
#endif
