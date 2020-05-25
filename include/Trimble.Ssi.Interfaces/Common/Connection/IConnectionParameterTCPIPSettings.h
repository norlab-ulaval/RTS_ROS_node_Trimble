#ifndef  ICONNECTIONPARAMETERTCPIPSETTINGS_H_
#define  ICONNECTIONPARAMETERTCPIPSETTINGS_H_

#include "IConnectionParameterExternalSettings.h"
#include <string>

namespace SSI
{
	/**
	* Connection parameter settings for a TCP/IP connection.
	*/
	class IConnectionParameterTCPIPSettings: public IConnectionParameterExternalSettings
	{
	public:
		virtual ~IConnectionParameterTCPIPSettings();

		/**
		* get connection parameter type
		* @return the connection Parameter type
		*/
		ConnectionParameterType getConnectionParameterType() const;

		/**
		* Get the IP address of the WiFi device.
		* @return the IP address
		*/
		virtual std::string getIPV4Address() const = 0;

		/**
		* Get the TCP/IP port of the WiFi device.
		* @return the TCP/IP address
		*/
		virtual int getTCPIPPort() const = 0;

		/**
		* Set the IP address of the WiFi device.
		* @return the IP address
		*/
		virtual void setIPV4Address(std::string ipAddress) = 0;

		/**
		* Set the TCP/IP port of the WiFi device.
		* @return the TCP/IP address
		*/
		virtual void setTCPIPPort(int port) = 0;
	};
}
#endif
