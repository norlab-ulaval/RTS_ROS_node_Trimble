#ifndef IRUNTIMELEFTINFO_H_
#define IRUNTIMELEFTINFO_H_

#include "IValuedServiceInfo.h"

namespace SSI
{
	/**
	* Represents a service information about how long the instrument can run until service is due.
	* @see ISsiServiceInfo
	*/
	class IRuntimeLeftInfo : public IValuedServiceInfo<int>
	{
	public:
		virtual ~IRuntimeLeftInfo();
	};
}
#endif