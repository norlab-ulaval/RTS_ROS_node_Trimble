#ifndef ISERVICEREQUIREDINFO_H_
#define ISERVICEREQUIREDINFO_H_

#include "IValuedServiceInfo.h"

namespace SSI
{
	/**
	* Represents a service information providing members about whether service is required or not.
	* @see ISsiServiceInfo
	*/
	class IServiceRequiredInfo : public IValuedServiceInfo<bool>
	{
	public:
		virtual ~IServiceRequiredInfo();
	};
}
#endif