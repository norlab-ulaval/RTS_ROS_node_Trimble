#ifndef OPERATIONCANCELEDEXCEPTION_H
#define OPERATIONCANCELEDEXCEPTION_H

#include "SsiException.h"

namespace SSI
{
	/**
	*  The operation was canceled exception.
	*/
	class OperationCanceledException : public SsiException
	{
	public:
		/**
		* constructor.
		* @param message exception message
		* @param errorCode error code
		*/
		OperationCanceledException(const char* message, int errorCode);
		OperationCanceledException(const char * operationDescription,const char* message, int errorCode);
		OperationCanceledException(const OperationCanceledException& copyMe);
	private:
		OperationCanceledException();
		OperationCanceledException& operator=(const OperationCanceledException&);
	};
}
#endif