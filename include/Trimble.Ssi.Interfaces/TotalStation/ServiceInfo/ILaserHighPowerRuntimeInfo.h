#ifndef ILASERHIGHPOWERRUNTIMEINFO_H_
#define ILASERHIGHPOWERRUNTIMEINFO_H_

#include "IValuedServiceInfo.h"

namespace SSI
{
	/**
	* Represents a service information providing members about high power runtime information.
	* @see ISsiServiceInfo
	*/
	class ILaserHighPowerRuntimeInfo : public IValuedServiceInfo<int>
	{
	public:
		virtual ~ILaserHighPowerRuntimeInfo(void);
	};
}
#endif