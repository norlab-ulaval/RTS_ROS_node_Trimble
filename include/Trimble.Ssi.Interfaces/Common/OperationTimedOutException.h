#ifndef OPERATIONTIMEDOUTEXCEPTION_H_
#define OPERATIONTIMEDOUTEXCEPTION_H_

#include "SsiException.h"

namespace SSI
{
	/**
	* The operation timed out exception.
	*/
	class OperationTimedOutException : public SsiException
	{
	public:
		/**
		* constructor.
		* @param message exception message
		* @param errorCode error code
		*/
		OperationTimedOutException(const char* message, const int errorCode);
		OperationTimedOutException(const char * operationDescription,const char* message, int errorCode);
		OperationTimedOutException(const OperationTimedOutException& copyMe);
	private:
		OperationTimedOutException();
		OperationTimedOutException& operator=(const OperationTimedOutException&);
	};
}
#endif