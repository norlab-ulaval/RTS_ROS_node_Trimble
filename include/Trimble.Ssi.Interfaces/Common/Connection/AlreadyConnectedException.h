#ifndef ALREADYCONNECTEDEXCEPTION_H_
#define ALREADYCONNECTEDEXCEPTION_H_

#include "../SsiException.h"

namespace SSI
{
	class AlreadyConnectedException : public SsiException
	{
	public:
		AlreadyConnectedException(const char* message, int errorCode);
		AlreadyConnectedException(const AlreadyConnectedException& copyMe);
	private:
		AlreadyConnectedException();
		AlreadyConnectedException& operator=(const AlreadyConnectedException&);
	};
}
#endif
