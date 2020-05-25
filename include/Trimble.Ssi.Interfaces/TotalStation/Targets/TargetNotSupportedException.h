#ifndef TARGETNOTSUPPORTEDEXCEPTION_H_
#define TARGETNOTSUPPORTEDEXCEPTION_H_

#include "../Common/SsiException.h"

namespace SSI
{
	/**
	* Target not supported exception.
	*/
	class TargetNotSupportedException : public SsiException
	{
	public:
		/**
		* constructor.
		* @param const char* exception message
		* @param int error code
		*/
		TargetNotSupportedException(const char* msg, int errorCode);
		TargetNotSupportedException(const TargetNotSupportedException& copyMe);
	private:
		TargetNotSupportedException();
		TargetNotSupportedException& operator=(const TargetNotSupportedException&);
	};
}
#endif