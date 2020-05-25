#ifndef IPRISMFINELOCKLONGRANGETARGET_H_
#define IPRISMFINELOCKLONGRANGETARGET_H_

#include "IPrismFinelockTarget.h"

namespace SSI
{
	/** Represents a Finelock Long Range target.
	* Only supported from %Trimble SSeries with additional sensor. It is not supporting distance tracking.
	* Range to passive prisms from 20 m to 2500 m.
	* @see ISsiTargets
	*/
	class IPrismFinelockLongRangeTarget : public IPrismFinelockTarget
	{
	public:
		virtual ~IPrismFinelockLongRangeTarget();
	};
}
#endif