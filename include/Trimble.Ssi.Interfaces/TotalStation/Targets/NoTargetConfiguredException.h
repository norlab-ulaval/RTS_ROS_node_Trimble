#ifndef NOTARGETCONFIGUREDEXCEPTION_H_
#define NOTARGETCONFIGUREDEXCEPTION_H_

#include "../Common/SsiException.h"

namespace SSI
{
	/**
	* No target configured exception.
	*/
	class NoTargetConfiguredException : public SsiException
	{
	public:
		/**
		* constructor.
		* @param const char* exception message
		* @param int error code
		*/
		NoTargetConfiguredException(const char* msg, int errorCode);
	private:
		NoTargetConfiguredException();
		NoTargetConfiguredException(const NoTargetConfiguredException& copyMe);
		NoTargetConfiguredException& operator=(const NoTargetConfiguredException&);
	};
}
#endif