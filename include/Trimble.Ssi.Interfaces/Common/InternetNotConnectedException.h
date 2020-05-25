#ifndef INTERNETNOTCONNECTEDEXCEPTION_H_
#define INTERNETNOTCONNECTEDEXCEPTION_H_

#include "SsiException.h"

namespace SSI
{
	/**
	* The not connected exception.
	*/
	class InternetNotConnectedException : public SsiException
	{
	public:
		/**
		* constructor.
		* @param operationDescription exception causing operation
		* @param errorCode error code
		*/
		InternetNotConnectedException(const char* operationDescription, const int errorCode);
		InternetNotConnectedException(const InternetNotConnectedException& copyMe);
	private:
		InternetNotConnectedException();
		InternetNotConnectedException& operator=(const InternetNotConnectedException&);
	};
}
#endif
