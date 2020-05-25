#ifndef ITRIMBLEMULTITRACKPASSIVETARGET_H_
#define ITRIMBLEMULTITRACKPASSIVETARGET_H_

#include "IPrismAdvancedTarget.h"

namespace SSI
{
	/**
	* Represents a passive %Trimble MultiTrack 1000 target.
	* Part.No. 58003013, prism constant 10 mm.
	* @see ISsiTargets
	*/
	class ITrimbleMultiTrackPassiveTarget : public IPrismAdvancedTarget
	{
	public:
		virtual ~ITrimbleMultiTrackPassiveTarget();
	};
}
#endif