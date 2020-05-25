#ifndef OPERATIONNOTSUPPORTEDEXCEPTION_H_
#define OPERATIONNOTSUPPORTEDEXCEPTION_H_

#include "SsiException.h"

namespace SSI
{
	/**
	* The operation timed out exception.
	*/
	class OperationNotSupportedException : public SsiException
	{
	public:
		/**
		* constructor.
		* @param message exception message
		* @param errorCode error code
		*/
		OperationNotSupportedException(const char* message, const int errorCode);
		OperationNotSupportedException(const char * operationDescription,const char* message, int errorCode);
		OperationNotSupportedException(const OperationNotSupportedException& copyMe);
	private:
		OperationNotSupportedException();
		OperationNotSupportedException& operator=(const OperationNotSupportedException&);
	};
}
#endif