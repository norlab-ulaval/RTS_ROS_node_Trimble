#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
#include <sys/types.h>
#include <algorithm>

#include "USBCommunicator.h"

using namespace Common;

USBCommunicator::USBCommunicator(int vid, int pid)
: _usb_vid(vid), _usb_pid(pid), _usb_handle(0), _usb_ctx(0), _recvbuf(0), _messageListener(0), _status(CS_DISCONNECTED)
{
    _recvbuf = new unsigned char[_BUFFERSIZE];
	int ret = libusb_init(&_usb_ctx);
	if (ret != 0)
	{
		printf("ss");
	}
}

USBCommunicator::~USBCommunicator()
{
    delete _recvbuf;
	libusb_exit(_usb_ctx);
}

bool FindUSB(libusb_context *ctx, int vid, int pid, libusb_device* &dev)
{
	libusb_device **devs;
	ssize_t cnt = libusb_get_device_list(ctx, &devs);
	for (ssize_t i = 0; i < cnt; i++)
	{
		libusb_device_descriptor desc;
		if (libusb_get_device_descriptor(devs[i], &desc) == 0)
		{
			if (desc.idVendor == vid && desc.idProduct == pid)
			{
				dev = devs[i];
				return true;
			}
		}
	}
	return false;
}

bool FindEndPoint(libusb_device* dev, int& in, int& out)
{
	bool bIn = false, bOut = false;
	libusb_config_descriptor *config;
	libusb_get_config_descriptor(dev, 0, &config);

	const libusb_interface_descriptor *interdesc;
	const libusb_endpoint_descriptor *epdesc;

	interdesc = &config->interface[0].altsetting[0];
	for (int k = 0; k < (int)interdesc->bNumEndpoints; k++)
	{
		epdesc = &interdesc->endpoint[k];
		if (epdesc->bEndpointAddress & LIBUSB_ENDPOINT_IN)
		{
			in = epdesc->bEndpointAddress;
			bIn = true;
		}
		else
		{
			out = epdesc->bEndpointAddress;
			bOut = true;
		}
	}

	libusb_free_config_descriptor(config);

	return bIn && bOut;
}

bool USBCommunicator::connect()
{
    _status = CS_CONNECTING;

	libusb_device* dev = 0;
	if (!FindUSB(_usb_ctx, _usb_vid, _usb_pid, dev))
	{
		return false;
	}

	//int ret = libusb_open(dev, &_usb_handle);
	//if (ret != 0)
	//{
	//	return false;
	//}

	_usb_handle = libusb_open_device_with_vid_pid(_usb_ctx, _usb_vid, _usb_pid);

	if (!_usb_handle)
	{
		return false;
	}

	if (libusb_kernel_driver_active(_usb_handle, 0) == 1)
	{
		libusb_detach_kernel_driver(_usb_handle, 0);
	}

	if (!FindEndPoint(libusb_get_device(_usb_handle), _usb_endpoint_in, _usb_endpoint_out))
	{
		libusb_close(_usb_handle);
		return false;
	}

	if (libusb_claim_interface(_usb_handle, 0) < 0)
	{
		libusb_close(_usb_handle);
		return false;
	}

    _status = CS_CONNECTED;
    _thread = std::thread([&]() { readThread(); });

    return true;
}

bool USBCommunicator::cancelConnect()
{
    return true;
}

bool USBCommunicator::disconnect()
{
    _status = CS_DISCONNECTING;

    if (_thread.joinable())
    {
        _thread.join();
        _thread = std::thread();
    }

	if (_usb_handle)
	{
		libusb_release_interface(_usb_handle, 0);
		libusb_close(_usb_handle);
		_usb_handle = 0;
	}

    _status = CS_DISCONNECTED;
    return true;
}

void USBCommunicator::addConnectionStateChangedListener(IConnectionStateChangedListener & listener)
{
    std::lock_guard<std::mutex> lock(_mutex);
    _connectionStateListeners.push_back(&listener);
}

void USBCommunicator::removeConnectionStateChangedListener(IConnectionStateChangedListener & listener)
{
    std::lock_guard<std::mutex> lock(_mutex);
    auto found = std::find(_connectionStateListeners.begin(), _connectionStateListeners.end(), &listener);
    if (found != _connectionStateListeners.end())
    {
        _connectionStateListeners.erase(found);
    }
}

ConnectionState USBCommunicator::getConnectionState() const
{
    return _status;
}

void USBCommunicator::pushMessage(const unsigned char* message, unsigned int length)
{
    if (_status == CS_CONNECTED)
    {
		int nwritten;
		if (libusb_bulk_transfer(_usb_handle, _usb_endpoint_out, (unsigned char*)message, length, &nwritten, 2000) != 0)
		{
			if (_status == CS_CONNECTED)
			{
				_status = CS_LINKDOWN;
				sendConnectionStatus();
			}
		}
    }
}

void USBCommunicator::onNewByteReceived(unsigned char receivedByte)
{
}

void USBCommunicator::setMessageReceivedListener(IMessageReceivedListener & listener)
{
    _messageListener = &listener;
}

void USBCommunicator::onNewMessageReceived(const unsigned char * receivedMessage, unsigned int length)
{
}

void USBCommunicator::sendConnectionStatus()
{
    std::lock_guard<std::mutex> lock(_mutex);
    for (auto ls = _connectionStateListeners.begin(); ls != _connectionStateListeners.end(); ls++)
    {
        (*ls)->onConnectionStateChanged(_status);
    }
}

void USBCommunicator::readThread()
{
    while (_status == CS_CONNECTED)
    {
		int nread = 0;
		int ret = libusb_bulk_transfer(_usb_handle, _usb_endpoint_in, (unsigned char*)_recvbuf, _BUFFERSIZE, &nread, 2000);
        if (ret == 0)
        {
            if (_messageListener)
            {
                _messageListener->onMessageReceived(_recvbuf, nread);
            }
        }
		else if (ret == LIBUSB_ERROR_TIMEOUT)
		{
			continue;
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
