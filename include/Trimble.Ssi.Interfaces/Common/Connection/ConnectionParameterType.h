#ifndef CONNECTIONPARAMETERTYPE_H_
#define CONNECTIONPARAMETERTYPE_H_

namespace SSI
{
	/**
	*  Represents the type of a connection parameter.
	*  ISensor.ListSupportedConnectionParameterTypes to get an enumeration of valid connection parameter types with respect to a specified ConnectionType value.
	*  @see ConnectionSettings
	*  @see ISensor
	*/
	enum ConnectionParameterType
	{
		CPT_BluetoothSettings,	/**< Bluetooth parameters */
		CPT_WifiSettings,		/**< WiFi parameters */
		CPT_TCPIPSettings,		/**< TCPIP parameters */
		CPT_RadioSettings,		/**< Radio parameters */
		CPT_SerialSettings,		/**< Serial parameters */
		CPT_USBSettings,		/**< USB parameters */
		CPT_PukSettings,                /**< Puk parameter */
		CPT_PinSettings,                /**< Pin parameter */
		CPT_SerialNumberSettings        /**< Serial Number parameter */
	};
}
#endif
