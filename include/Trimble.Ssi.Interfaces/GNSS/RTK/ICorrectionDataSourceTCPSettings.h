#ifndef ICORRECTIONDATASOURCETCPSETTINGS_H_
#define ICORRECTIONDATASOURCETCPSETTINGS_H_

#include "ICorrectionDataSourceAdvanced.h"
#include "IRTKConnectionStatusListener.h"
#include <string>

namespace SSI
{
	class ICorrectionDataSourceTCPSettings : public virtual ICorrectionDataSource
	{
	public:
		virtual ~ICorrectionDataSourceTCPSettings();

		/**
		* register a listener for listening RTK connection status.
		* @param IRTKConnectionStatusListener to listen
		*/
		virtual void addConnectionStateListener(IRTKConnectionStatusListener& listener) = 0;

		/**
		* register a listener for listening RTK connection status.
		* @param IRTKConnectionStatusListener to listen
		*/
		virtual void removeConnectionStateListener(IRTKConnectionStatusListener& listener) = 0;

		/*
		* Gets the server address.
		* @return RTK server address
		*/
		virtual const std::string& getServerAddress() const=0;

		/*
		* Sets the server address.
		* @param serverAddress RTK server
		*/
		virtual void setServerAddress(std::string serverAddress)=0;

		/*
		* Gets server port.
		* @return RTK server port
		*/
		virtual int getServerPort() const=0;

		/*
		* Sets the server port.
		* @param port RTK server port
		*/
		virtual void setServerPort(int port)=0;
	};
}
#endif
