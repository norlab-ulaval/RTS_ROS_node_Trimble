#ifndef TARGETAIMINGPARAMETERTYPE_H_
#define TARGETAIMINGPARAMETERTYPE_H_

namespace SSI
{
	/**
	* Represents the type of a TargetAiming parameter.
	* To get an enumeration of supported TargetAimingParameter values, use ISsiTargetAiming::listSupportedParameterTypes.
	* Use ISsiTargetAiming::CreateParameter to create an ITargetAimingParameter based on the TargetAimingParameterType.
	*/
	enum TargetAimingParameterType
	{
		TAPT_LostTargetFollowTime	/**< use LostTargetFollowTime in seconds. */
	};
}
#endif