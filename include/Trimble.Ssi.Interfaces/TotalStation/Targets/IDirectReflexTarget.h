#ifndef IDIRECTREFLEXTARGET_H_
#define IDIRECTREFLEXTARGET_H_

#include "ITarget.h"

namespace SSI
{
	/**
	* Represents a direct reflex target with basic laser pointer capabilities.
	* The following table lists the maximum measurement distance under good conditions.
	* Instrument | Range
	* -----------|------
	* %Trimble M3 1", 2" | 400 m
	* %Trimble M3 3", 5" | 300 m
	* %Trimble S3 | 400 m
	* %Trimble S6 DR Plus | 1300 m
	* %Trimble S8 DR Plus | 1300 m
	* %Trimble S8 DR HP | 150 m
	* %Trimble VX | 1300 m
	* For detailed information see the appropriate device manual.
	* @see ISsiTargets
	*/
	class IDirectReflexTarget : public ITarget
	{
	public:
		virtual ~IDirectReflexTarget();

		/**
		* Sets a value indicating whether the laser pointer is used or not.
		* @param bool true if active; otherwise false
		*/
		virtual void setLaserPointerActive(bool activeState) = 0;
	
		/**
		* Gets a value indicating whether the laser pointer is used or not.
		* @return true if active; otherwise false
		*/
		virtual bool getLaserPointerActive() const = 0;
	};
}
#endif