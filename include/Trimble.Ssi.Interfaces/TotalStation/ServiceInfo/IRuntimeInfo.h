#ifndef IRUNTIMEINFO_H_
#define IRUNTIMEINFO_H_

#include "IValuedServiceInfo.h"

namespace SSI
{
	/**
	* Represents a service information about the instrument runtime.
	* @see ISsiServiceInfo
	*/
	class IRuntimeInfo : public IValuedServiceInfo<int>
	{
	public:
		virtual ~IRuntimeInfo();
	};
}
#endif