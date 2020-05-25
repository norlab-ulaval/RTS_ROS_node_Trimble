#ifndef ITRIMBLEACTIVETRACK360TARGET_H_
#define ITRIMBLEACTIVETRACK360TARGET_H_

#include "IPrismIdTarget.h"

namespace SSI
{
	/** Represents a %Trimble MultiTrack 900 target.
	* Part.No. xxxx, prism constant 22 mm.
	* @see ISsiTargets
	*/
	class ITrimbleActiveTrack360Target : public IPrismIdTarget
	{
	public:
		virtual ~ITrimbleActiveTrack360Target();
	};
}
#endif