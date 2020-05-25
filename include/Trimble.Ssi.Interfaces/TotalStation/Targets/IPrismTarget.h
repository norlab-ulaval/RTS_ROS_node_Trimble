#ifndef IPRISMTARGET_H_
#define IPRISMTARGET_H_

#include "ITarget.h"

namespace SSI
{
	/**
	* Represents a simple prism target.
	* The following table shows maximum distance of this target per instrument.
	* Instrument | Standard Deviation
	* -----------|-------------------
	* %Trimble M3 1", 2" | 3000 m
	* %Trimble M3 3", 5" |  5000 m
	* %Trimble S3 | 2500 m
	* %Trimble S6 DR Plus | 2500 m
	* %Trimble S8 DR Plus | 2500 m
	* %Trimble S8 DR HP | 3000 m
	* %Trimble VX | 2500 m
	* For detailed information see the appropriate device manual.
	*@see ISsiTargets
	*/
	class IPrismTarget : public ITarget
	{
	public:
		virtual ~IPrismTarget();
	};
}
#endif