#ifndef ICONNECTIONPARAMETERSERIALSETTINGS_H_
#define ICONNECTIONPARAMETERSERIALSETTINGS_H_

#include "IConnectionParameterExternalSettings.h"

namespace SSI
{
	/**
	* Represents a set of serial connection parameters.
	* @see ConnectionSettings
	* @see ISensor
	*/
	class IConnectionParameterSerialSettings : public IConnectionParameterExternalSettings
	{
	public:
		virtual ~IConnectionParameterSerialSettings();

		/**
		* get connection parameter type
		* @return the connection Parameter type
		*/
		ConnectionParameterType getConnectionParameterType() const;

		/**
		* Get the port.
		* @return The port.
		*/
		virtual int getPort() const = 0;

		/**
		* Set the port.
		* @param port The port.
		*/
		virtual void setPort(int port) = 0;
	};
}
#endif
