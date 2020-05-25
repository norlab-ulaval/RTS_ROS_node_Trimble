#ifndef IVALUEDSERVICEINFO_H_
#define IVALUEDSERVICEINFO_H_

#include "IServiceInfo.h"

namespace SSI
{
	/** Represents a basic generic service information data with a TValue such as INextServiceDateInfo,
	* IRuntimeInfo, IRuntimeLeftInfo and IServiceRequiredInfo.
	*/
	template<class T>
	class IValuedServiceInfo : public IServiceInfo
	{
	public:
		/**
		* Get the service info value.
		* @return the service info value
		*/
		virtual T getValue() const = 0;
	};
}
#endif