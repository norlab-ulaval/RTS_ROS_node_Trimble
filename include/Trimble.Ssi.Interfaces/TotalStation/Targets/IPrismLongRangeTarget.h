#ifndef IPRISMLONGRANGETARGET_H_
#define IPRISMLONGRANGETARGET_H_

#include "IPrismTarget.h"

namespace SSI
{
	/** Represents a Long Range target.
	* Only supported for manual measurements to passive prism.
	* The following table shows the maximum distance per instrument.
	* Instrument | Maximum Distance
	* -----------|-----------------
	* %Trimble S6 DR Plus | 5500 m
	* %Trimble S8 DR Plus | 5500 m
	* %Trimble S8 DR HP | 5000 m
	* %Trimble VX | 5500 m
	* For detailed information see the appropriate device manual.
	* @see ISsiTargets
	*/
	class IPrismLongRangeTarget : public IPrismTarget
	{
	public:
		virtual ~IPrismLongRangeTarget();
	};
}
#endif