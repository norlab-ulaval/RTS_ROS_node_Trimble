#ifndef ITARGET_H_
#define ITARGET_H_

#include "TargetType.h"

namespace SSI
{
	/**
	* Represents a basic target.
	* Use ISsiTargets::CreateTarget to create an ITargetby it's type.
	* @see ISsiTargets
	*/
	class ITarget
	{
	public:
		virtual ~ITarget();

		/**
		* get the target type.
		* @return the target type
		*/
		virtual TargetType getTargetType() const = 0;
	};
}
#endif