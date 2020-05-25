#ifndef INEXTSERVICEDATEINFO_H_
#define INEXTSERVICEDATEINFO_H_

#include "IValuedServiceInfo.h"

namespace SSI
{
	/**
	* Represents a service information about the next service date.
	* @see ISsiServiceInfo
	*/
	class INextServiceDateInfo : public IValuedServiceInfo<long long>
	{
	public:
		virtual ~INextServiceDateInfo();
	};
}
#endif