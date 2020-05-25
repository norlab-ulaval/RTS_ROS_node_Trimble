#ifndef IDIRECTREFLEXHIGHPOWERLASERTARGET_H_
#define IDIRECTREFLEXHIGHPOWERLASERTARGET_H_

#include "IDirectReflexTarget.h"

namespace SSI
{
	/** Represents a direct reflex target with the eccentrically 3R laser pointer.
	* @see ISsiTargets
	*/
	class IDirectReflexHighPowerLaserTarget : public IDirectReflexTarget
	{
	public:
		virtual ~IDirectReflexHighPowerLaserTarget();
	
		/** Gets the laser offset.
		* @return The laser offset.
		*/
		virtual double getLaserOffset() const = 0;
	};
}
#endif