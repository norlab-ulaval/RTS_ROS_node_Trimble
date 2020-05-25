#ifndef ITCPCOMMUNICATOR_H_
#define ITCPCOMMUNICATOR_H_

#include "Connection/ICommunicator.h"
#include <string>

namespace SSI
{
	class ITCPCommunicator :public Common::ICommunicator
	{
	public:
		virtual ~ITCPCommunicator();
		virtual bool setTarget(std::string ipAddress,int port)=0;
	};
}
#endif