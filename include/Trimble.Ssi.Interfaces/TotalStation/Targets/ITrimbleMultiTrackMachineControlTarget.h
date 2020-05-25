#ifndef ITRIMBLEMULTITRACKMACHINECONTROLTARGET_H_
#define ITRIMBLEMULTITRACKMACHINECONTROLTARGET_H_

#include "IPrismIdTarget.h"

namespace SSI
{
	/** Represents a %Trimble MultiTrack 900 target.
	* Part.No. 58500-05, prism constant 42 mm.
	* @see ISsiTargets
	*/
	class ITrimbleMultiTrackMachineControlTarget : public IPrismIdTarget
	{
	public:
		virtual ~ITrimbleMultiTrackMachineControlTarget();
	};
}
#endif