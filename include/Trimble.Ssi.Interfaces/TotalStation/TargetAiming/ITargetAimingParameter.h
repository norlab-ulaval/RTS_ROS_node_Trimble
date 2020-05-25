#ifndef ITARGETAIMINGPARAMETER_H_
#define ITARGETAIMINGPARAMETER_H_

#include "TargetAimingParameterType.h"

namespace SSI
{
	/**
	* Represents a basic TargetAiming parameter used with the ISsiTargetAiming interface.
	* @see ISsiTargetAiming
	*/
	class ITargetAimingParameter
	{
	public:
		virtual ~ITargetAimingParameter();
	
		/**
		* get the TargetAiming parameter type
		* @return the TargetAiming parameter type
		*/
		virtual TargetAimingParameterType Type() const = 0;
	};
}
#endif