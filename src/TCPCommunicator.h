#pragma once
#include "Connection/ICommunicator.h"
#include <string>
#include <vector>
#include <thread>
#include <mutex>

namespace Common
{
    class TCPCommunicator : public ICommunicator
    {
    public:
        TCPCommunicator(const std::string& ip, int port);
        virtual ~TCPCommunicator();

        virtual bool connect();
        virtual bool cancelConnect();
        virtual bool disconnect();
        virtual void addConnectionStateChangedListener(IConnectionStateChangedListener& listener);
        virtual void removeConnectionStateChangedListener(IConnectionStateChangedListener& listener);
        virtual ConnectionState getConnectionState() const;
        virtual void pushMessage(const unsigned char* message, unsigned int length);
        virtual void setMessageReceivedListener(IMessageReceivedListener& listener);

    private:
        virtual void onNewMessageReceived(const unsigned char* receivedMessage, unsigned int length);
        void sendConnectionStatus();
        void readThread();

        std::string _ip;
        int _port;
        int _sockfd;
        unsigned char* _recvbuf;
        static const int _BUFFERSIZE = 64 * 1024;

        std::vector<IConnectionStateChangedListener*> _connectionStateListeners;
        IMessageReceivedListener* _messageListener;
        std::mutex _mutex;
        ConnectionState _status;
        std::thread _thread;
    };
}
