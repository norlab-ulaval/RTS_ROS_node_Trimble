#ifndef IPRISM360DEGREETARGET_H_
#define IPRISM360DEGREETARGET_H_

#include "IPrismWithSizeTarget.h"
#include "Prism360DegreeTargetLockMode.h"

namespace SSI
{
	/**
	* Represents a 360 degree target made of several prism.
	* <seealso cref="ISsiTargets"/>
	*/
	class IPrism360DegreeTarget : public IPrismWithSizeTarget
	{
	public:
		virtual ~IPrism360DegreeTarget();

		/** Gets the current target lock mode.
		* @return Mode of the current target lock mode.
		*/
		virtual Prism360DegreeTargetLockMode getTargetLockMode() const = 0;
		
		/** Sets the current target lock mode.
		* @param the target lock mode 
		*/
		virtual void setTargetLockMode(Prism360DegreeTargetLockMode targetlockMode) = 0;

		/** Returns a list of all target lock modes.
		* @return List of all target lock modes.
		*/
		virtual std::vector<Prism360DegreeTargetLockMode> listSupportedTargetLockModes() const = 0;
		
		/**
		* is the target lock mode supported ?
		* @param check target lock mode
		* @return true if it is otherwise false
		*/
		virtual bool isTargetLockModeSupported(Prism360DegreeTargetLockMode targetLockMode) const = 0;
	};
}
#endif