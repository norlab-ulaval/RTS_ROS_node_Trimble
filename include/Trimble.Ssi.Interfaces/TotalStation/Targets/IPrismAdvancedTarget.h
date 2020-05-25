#ifndef IPRISMADVANCEDTARGET_H_
#define IPRISMADVANCEDTARGET_H_

#include "IPrismTarget.h"
#include "WorkingMode.h"
#include "TargetState.h"

#include <vector>

namespace SSI
{
	/**
	* Represents an advanced prism target providing members for locking of targets.
	* @see ISsiTargets
	*/
	class IPrismAdvancedTarget : public IPrismTarget
	{
	public:
		virtual ~IPrismAdvancedTarget();

		/**
		* set the working mode of the target.
		* @param WorkingMode of the target
		*/
		virtual void setWorkingMode(WorkingMode workingMode) = 0;

		/**
		* get the working mode of the target.
		* @return the working mode
		*/
		virtual WorkingMode getWorkingMode() const = 0;

		/**
		* Get a collection of available working modes.
		* @return the working modes
		*/
		virtual std::vector<WorkingMode> listSupportedWorkingModes() const = 0;

		/**
		* is the Working mode supported ?
		* @param WorkingMode to check
		* @return true if it is otherwise false
		*/
		virtual bool isWorkingModeSupported(WorkingMode workingMode) const = 0;
	
		/** Gets the current target state.
		* @return State of the target.
		* @see ISsiTargets.TargetChanged event is raised when the state changes.
		*/
		virtual TargetState getState() const = 0;
	};
}
#endif