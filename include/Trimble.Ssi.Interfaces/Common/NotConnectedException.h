#ifndef NOTCONNECTEDEXCEPTION_H_
#define NOTCONNECTEDEXCEPTION_H_

#include "SsiException.h"

namespace SSI
{
	/**
	* The not connected exception.
	*/
	class NotConnectedException : public SsiException
	{
	public:
		/**
		* constructor.
		* @param message exception message
		* @param errorCode error code
		*/
		NotConnectedException(const char* msg, const int errorCode);
		NotConnectedException(const char * operationDescription,const char* msg, int errorCode);
		NotConnectedException(const NotConnectedException& copyMe);
	private:
		NotConnectedException();
		NotConnectedException& operator=(const NotConnectedException&);
	};
}
#endif