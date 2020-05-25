#ifndef ILASERSERVICEREQUIREDINFO_H_
#define ILASERSERVICEREQUIREDINFO_H_

#include "IValuedServiceInfo.h"

namespace SSI
{
	/**
	* Represents a service information providing members about whether laser service is required or not.
	* @see ISsiServiceInfo
	*/
	class ILaserNeedsServiceInfo :	public IValuedServiceInfo<bool>
	{
	public:
		virtual ~ILaserNeedsServiceInfo(void);
	};
}
#endif