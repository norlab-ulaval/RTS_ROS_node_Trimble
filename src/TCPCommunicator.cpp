
#ifdef _WIN32
#include <WinSock2.h>
#pragma comment(lib, "ws2_32")
#else
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <algorithm>
#define closesocket close
#endif

#include "TCPCommunicator.h"

using namespace Common;

void initSocket()
{
#ifdef _WIN32
    static bool binit = false;
    if (!binit)
    {
        WSADATA w;
        if (WSAStartup(0x0002, &w) != 0)
        {
        }
        binit = true;
    }
#endif
}

TCPCommunicator::TCPCommunicator(const std::string& ip, int port)
: _ip(ip), _port(port), _sockfd(-1), _recvbuf(0), _messageListener(0), _status(CS_DISCONNECTED)
{
    initSocket();
    _recvbuf = new unsigned char[_BUFFERSIZE];
}

TCPCommunicator::~TCPCommunicator()
{
    delete _recvbuf;
}

bool TCPCommunicator::connect()
{
    _status = CS_CONNECTING;
    struct sockaddr_in servaddr;
    _sockfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(_ip.c_str());
    servaddr.sin_port = htons(_port);

    if (::connect(_sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
    {
        closesocket(_sockfd);
        _sockfd = -1;
        return false;
    }

    _status = CS_CONNECTED;
    _thread = std::thread([&]() { readThread(); });

    return true;
}

bool TCPCommunicator::cancelConnect()
{
    return true;
}

bool TCPCommunicator::disconnect()
{
    _status = CS_DISCONNECTING;
    if (_sockfd != -1)
    {
        shutdown(_sockfd, 2);
        closesocket(_sockfd);
        _sockfd = -1;
    }

    if (_thread.joinable())
    {
        _thread.join();
        _thread = std::thread();
    }
    _status = CS_DISCONNECTED;
    return true;
}

void TCPCommunicator::addConnectionStateChangedListener(IConnectionStateChangedListener & listener)
{
    std::lock_guard<std::mutex> lock(_mutex);
    _connectionStateListeners.push_back(&listener);
}

void TCPCommunicator::removeConnectionStateChangedListener(IConnectionStateChangedListener & listener)
{
    std::lock_guard<std::mutex> lock(_mutex);
    auto found = std::find(_connectionStateListeners.begin(), _connectionStateListeners.end(), &listener);
    if (found != _connectionStateListeners.end())
    {
        _connectionStateListeners.erase(found);
    }
}

ConnectionState TCPCommunicator::getConnectionState() const
{
    return _status;
}

void TCPCommunicator::pushMessage(const unsigned char * message, unsigned int length)
{
    if (_status == CS_CONNECTED)
    {
        int ret = send(_sockfd, (const char*)message, length, 0);
		if (ret < 0)
		{
			if (_status == CS_CONNECTED)
			{
				_status = CS_LINKDOWN;
				sendConnectionStatus();
			}
		}
    }
}

void TCPCommunicator::setMessageReceivedListener(IMessageReceivedListener & listener)
{
    _messageListener = &listener;
}

void TCPCommunicator::onNewMessageReceived(const unsigned char * receivedMessage, unsigned int length)
{
}

void TCPCommunicator::sendConnectionStatus()
{
    std::lock_guard<std::mutex> lock(_mutex);
    for (auto ls = _connectionStateListeners.begin(); ls != _connectionStateListeners.end(); ls++)
    {
        (*ls)->onConnectionStateChanged(_status);
    }
}

void TCPCommunicator::readThread()
{
    while (_status == CS_CONNECTED)
    {
        int nread = recv(_sockfd, (char*)_recvbuf, _BUFFERSIZE, 0);
        if (nread > 0)
        {
            if (_messageListener)
            {
                _messageListener->onMessageReceived(_recvbuf, nread);
            }
        }
        else
        {
            if (_status == CS_CONNECTED)
            {
                _status = CS_LINKDOWN;
                sendConnectionStatus();
            }
            break;
        }
    }
}
