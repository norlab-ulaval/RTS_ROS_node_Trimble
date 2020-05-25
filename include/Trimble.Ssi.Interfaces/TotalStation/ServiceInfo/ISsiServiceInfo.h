#ifndef ISSISERVICEINFO_H_
#define ISSISERVICEINFO_H_

#include "ISsiInterface.h"
#include "ServiceInfoType.h"
#include "IServiceInfo.h"

namespace SSI
{
	/**
	* Provides members to access the instruments service information.
	* For a brief description of features and usage of various ISsiInterface see [Guides: Interfaces](@ref Guides_Interfaces)
	*/
	class ISsiServiceInfo : public ISsiInterface
	{
	public:
		virtual ~ISsiServiceInfo();

		/**
		* Tries to get an IServiceInfo instance of type TServiceInfo.
		* @param ServiceInfoType Type of the IServiceInfo instance which is requested.
		* @return An instance of the requested IServiceInfo if supported; otherwise null
		*/
		virtual IServiceInfo* getInfo(ServiceInfoType serviceInfoType) = 0;
	};
}
#endif