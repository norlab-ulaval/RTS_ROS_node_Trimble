#ifndef IGREENHIGHPOWERLASERTARGET_H_
#define IGREENHIGHPOWERLASERTARGET_H_

#include "ITarget.h"
#include "GreenHighPowerLaserMode.h"
#include "GreenHighPowerLaserState.h"

namespace SSI
{
	/**
	* Represents an green high power laser target.
	* @see ISsiTargets
	*/
	class IGreenHighPowerLaserTarget : public ITarget
	{
	public:
		virtual ~IGreenHighPowerLaserTarget();

		/**
		* set the laser mode will be used.
		* @param laserMode of the target
		*/
		virtual void setLaserMode(GreenHighPowerLaserMode laserMode) = 0;

		/**
		* get the current laser mode.
		* @return the laser mode
		*/
		virtual GreenHighPowerLaserMode getLaserMode() const = 0;

		/**
		* set the GPL Servo focus distance.
		* @param distance to be set
		*/
		virtual void setDistance(double distance) = 0;

		/**
		* get the GPL Servo focus distance.
		* @return current servo focus distance
		*/
		virtual double getDistance() const = 0;
	
		/** Gets the current laser state.
		* @return current Power laser state of the target.
		* @see ISsiTargets.TargetChanged event is raised when the state changes.
		*/
		virtual GreenHighPowerLaserState getState() const = 0;
	};
}
#endif