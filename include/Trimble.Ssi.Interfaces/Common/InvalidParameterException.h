#ifndef INVALIDPARAMETEREXCEPTION_H_
#define INVALIDPARAMETEREXCEPTION_H_

#include "SsiException.h"

namespace SSI
{
	/**
	* The invalid parameter exception.
	*/
	class InvalidParameterException : public SsiException
	{
	public:
		/**
		* constructor.
		* @param message exception message
		* @param errorCode error code
		*/
		InvalidParameterException(const char* message, const int errorCode);
		InvalidParameterException(const char * operationDescription, const char* message, int errorCode);
		InvalidParameterException(const InvalidParameterException& copyMe);
	private:
		InvalidParameterException();
		InvalidParameterException& operator=(const InvalidParameterException&);
	};
}
#endif