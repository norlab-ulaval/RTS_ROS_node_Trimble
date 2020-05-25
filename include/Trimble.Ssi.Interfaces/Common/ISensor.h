#ifndef ISENSOR_H_
#define ISENSOR_H_

#include "ISsiInterfaceProvider.h"
#include "Connection/IConnectionStateChangedListener.h"
#include "Connection/ConnectionSettings.h"
#include "Connection/ConnectionState.h"
#include "Connection/ConnectionType.h"
#include "Connection/ConnectionParameterType.h"
#include "Connection/IConnectionParameter.h"
#include "DisconnectMode.h"

#include <vector>

namespace SSI
{
	/**
	* Represents a sensor providing members for connection establishment and retrieving of sensor features.
	* This is the generic sensor interface to be used with all sensor types.
	* Use Idriver::CreateSensor to create a sensor implementation based on the drivers model.
	* @see IDriver
	*/
	class ISensor : public ISsiInterfaceProvider
	{
	public:
		virtual ~ISensor();

		/**
		* Register a listener to get informed when events happen.
		* @param listener the listener to register
		*/
		virtual void addConnectionStateChangedListener(Common::IConnectionStateChangedListener& listener) = 0;

		/**
		* Unregister a listener.
		* @param listener the listener to unsubscribe
		*/
		virtual void removeConnectionStateChangedListener(Common::IConnectionStateChangedListener& listener) = 0;

		/**
		* Get the connection settings which where last used to connect to the sensor.
		* @return the connection settings
		*/
		virtual const ConnectionSettings& getConnectionSettings() const = 0;

		/**
		* Get the state of the connection.
		* @return the connection state
		*/
		virtual Common::ConnectionState getConnectionState() const = 0;

		/**
		* Checks if a connection type is supported.
		* @param connectionType to check
		* @return if it is supported or not
		*/
		virtual bool isConnectionTypeSupported(ConnectionType connectionType) const = 0;

		/**
		* Checks if a connection parameter type is supported.
		* @param connectionType to which the connection parameter type belongs
		* @param connectionParameterType to check if it is supported
		* @return if it is supported or not
		*/
		virtual bool isConnectionParameterTypeSupported(ConnectionType connectionType, ConnectionParameterType connectionParameterType) const = 0;

		/**
		* Returns the supported connection types.
		* @return the connection types
		*/
		virtual std::vector<ConnectionType> listSupportedConnectionTypes() const = 0;

		/**
		* Returns the supported connection parameters.
		* @return the supported connection parameters
		*/
		virtual std::vector<ConnectionParameterType> listSupportedConnectionParameterTypes(ConnectionType connectionType) const = 0;

		/**
		* Returns an enumeration of all available connection parameter types.
		* @param connectionParameterType the connection parameter type
		* @return the available connection parameter types
		*/
		virtual IConnectionParameter& createConnectionParameter(ConnectionParameterType connectionParameterType) const = 0;

		/**
		* Aborts a connection attempt.
		* Cancellation of a measurement, which has not been started yet does not affect
		* the state of the ISensor instance.
		* @see ISensor
		*/
		virtual void cancelConnect() = 0;

		/**
		* Disconnect from the sensor.
		*/
		virtual void disconnect() = 0;

		/**
		* Establish a connection to this sensor providing the connection settings.
		* @param connectionSettings the connection settings
		*/
		virtual void connect(const ConnectionSettings& connectionSettings) = 0;

		/**
		* Returns an enumeration of all available disconnect modes.
		*
		* @returns An enumeration of all available disconnect modes.
		* @remarks Use DisconnectMode to disconnect from a sensor.
		* @see DisconnectMode
		* @remarks Please be aware, that the underlying enumeration later may contain values, which are not known now.
		*/
		virtual std::vector<DisconnectMode> listSupportedDisconnectModes() const = 0;

		/**
		* Determines whether the specified disconnect mode is supported.
		*
		* @param disconnectMode
		*      The mode after disconnecting from the instrument.
		*
		* @returns DisconnectMode list
		*/
		virtual bool isSupported(DisconnectMode disconnectMode) const = 0;

		/**
		* Call this instance to disconnect from the sensor.
		*
		* @param disconnectMode
		*      The mode after disconnecting from the instrument.
		*/
		virtual void disconnect(DisconnectMode disconnectMode) = 0;
	};
}
#endif