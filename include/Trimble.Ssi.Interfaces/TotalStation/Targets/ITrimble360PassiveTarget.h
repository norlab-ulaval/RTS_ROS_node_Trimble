#ifndef ITRIMBLE360PASSIVETARGET_H_
#define ITRIMBLE360PASSIVETARGET_H_

#include "IPrismAdvancedTarget.h"

namespace SSI
{
	/**
	* Represents the passive %Trimble 360° target.
	* Part.No. 58128001, prism constant 2mm.
	* @see ISsiTargets
	*/
	class ITrimble360PassiveTarget : public IPrismAdvancedTarget
	{
	public:
		virtual ~ITrimble360PassiveTarget();
	};
}
#endif