#ifndef ITARGETAIMINGPARAMETERLOSTTARGETFOLLOWTIME_H_
#define ITARGETAIMINGPARAMETERLOSTTARGETFOLLOWTIME_H_

#include "ITargetAimingParameter.h"

namespace SSI
{
	/**
	* @see ISsiTargetAiming
	*/
	class ITargetAimingParameterLostTargetFollowTime : public ITargetAimingParameter
	{
	public:
		virtual ~ITargetAimingParameterLostTargetFollowTime();

		/**
		* get the TargetAiming parameter type.
		* @return the TargetAiming parameter type
		*/
		TargetAimingParameterType getTargetAimingParameterType() const;

		/**
		* get the LostTargetFollowTime.
		* @return the lostTargetFollowTime in seconds
		*/
		virtual double getLostTargetFollowTime() const = 0;
	
		/**
		* set the lostTargetFollowTime.
		* @param double the lostTargetFollowTime
		*/
		virtual void setLostTargetFollowTime(double lostTargetFollowTime) = 0;
	};
}
#endif