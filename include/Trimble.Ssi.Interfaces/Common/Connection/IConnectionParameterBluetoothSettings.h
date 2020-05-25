#ifndef ICONNECTIONPARAMETERBLUETOOTHSETTINGS_H_
#define ICONNECTIONPARAMETERBLUETOOTHSETTINGS_H_

#include "IConnectionParameterExternalSettings.h"
#include <string>

namespace SSI
{
	/**
	* Represents connection parameter type for a Bluetooth connection.
	*/
	class IConnectionParameterBluetoothSettings : public IConnectionParameterExternalSettings
	{
	public:
		virtual ~IConnectionParameterBluetoothSettings();

		/**
		* get the connection parameter type
		* @return connection parameter type
		*/
		ConnectionParameterType getConnectionParameterType() const;

		/**
		* Get the Bth Address.
		* @return The Address to be used
		*/
		virtual std::string getAddress() const = 0;

		/**
		* Set the Bth Address.
		* @param address The Address to be used
		*/
		virtual void setAddress(const std::string& address) = 0;
	};
}
#endif