#ifndef ILASERLOWPOWERRUNTIMEINFO_H_
#define ILASERLOWPOWERRUNTIMEINFO_H_

#include "IValuedServiceInfo.h"

namespace SSI
{
	/**
	* Represents a service information providing members about low power runtime information.
	* @see ISsiServiceInfo
	*/
	class ILaserLowPowerRuntimeInfo : public IValuedServiceInfo<int>
	{
	public:
		virtual ~ILaserLowPowerRuntimeInfo(void);
	};
}
#endif