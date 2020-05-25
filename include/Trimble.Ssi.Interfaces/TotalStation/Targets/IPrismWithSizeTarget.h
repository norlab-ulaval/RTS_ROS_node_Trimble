#ifndef IPRISMWITHSIZETARGET_H_
#define IPRISMWITHSIZETARGET_H_

#include "IPrismAdvancedTarget.h"

namespace SSI
{
	/**
	* Represents an prism target with configured size information providing members for locking of targets.
	* <seealso cref="ISsiTargets"/>
	*/
	class IPrismWithSizeTarget : public IPrismAdvancedTarget
	{
	public:
		virtual ~IPrismWithSizeTarget();

		/**
		* Gets the target size.
		* @return the Diameter of the target.
		*/
		virtual double getTargetSize() const = 0;
	
		/**
		* Sets the target size.
		* @return the Diameter of the target.
		*/
		virtual void setTargetSize(double targetSize) = 0;
	};
}
#endif