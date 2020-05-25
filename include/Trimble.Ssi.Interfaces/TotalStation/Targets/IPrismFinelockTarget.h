#ifndef IPRISMFINELOCKTARGET_H_
#define IPRISMFINELOCKTARGET_H_

#include "IPrismTarget.h"

namespace SSI
{
	/**
	* Represents a finelock target.
	* Only supported from %Trimble SSeries with additional sensor. It is not supporting distance tracking.
	* Range to passive prisms from 20 m to 700 m.
	* @see ISsiTargets
	*/
	class IPrismFinelockTarget : public IPrismTarget
	{
	public:
		virtual ~IPrismFinelockTarget();
	};
}
#endif