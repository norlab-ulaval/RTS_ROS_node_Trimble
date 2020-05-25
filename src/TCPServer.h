#pragma once
#include <string>
#include <memory>
#include <functional>

typedef std::shared_ptr<class TCPServer> TCPServerPtr;
typedef void* TCPConnectHandle;
typedef std::function<void(TCPConnectHandle handle, unsigned char* buffer, int length)> TCPRecvDataFun;

class TCPServer
{
public:
	virtual ~TCPServer() {}
	virtual void Run() = 0;
	virtual void Stop() = 0;
	virtual bool Send(TCPConnectHandle handle, unsigned char* buffer, int length) = 0;
	virtual bool SendtoAll(unsigned char* buffer, int length) = 0;

	static TCPServerPtr GetInstance(int port, TCPRecvDataFun fun);
};
