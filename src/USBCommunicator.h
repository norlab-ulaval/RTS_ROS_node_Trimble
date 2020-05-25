#pragma once
#include "Connection/ICommunicator.h"
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <libusb-1.0/libusb.h>

namespace Common
{
    class USBCommunicator : public ICommunicator
    {
    public:
        USBCommunicator(int vid, int pid);
        virtual ~USBCommunicator();

        virtual bool connect();
        virtual bool cancelConnect();
        virtual bool disconnect();
        virtual void addConnectionStateChangedListener(IConnectionStateChangedListener& listener);
        virtual void removeConnectionStateChangedListener(IConnectionStateChangedListener& listener);
        virtual ConnectionState getConnectionState() const;
        virtual void pushMessage(const unsigned char* message, unsigned int length);
        virtual void setMessageReceivedListener(IMessageReceivedListener& listener);

    private:
        virtual void onNewByteReceived(unsigned char receivedByte);
        virtual void onNewMessageReceived(const unsigned char* receivedMessage, unsigned int length);
        void sendConnectionStatus();
        void readThread();

		int _usb_vid;
		int _usb_pid;
		libusb_device_handle* _usb_handle;
		libusb_context* _usb_ctx;
		int _usb_endpoint_in;
		int _usb_endpoint_out;

        unsigned char* _recvbuf;
        static const int _BUFFERSIZE = 64 * 1024;

        std::vector<IConnectionStateChangedListener*> _connectionStateListeners;
        IMessageReceivedListener* _messageListener;
        std::mutex _mutex;
        ConnectionState _status;
        std::thread _thread;
    };
}
