#ifndef CONNECTIONTYPE_H_
#define CONNECTIONTYPE_H_

namespace SSI
{
	/**
	* Represents the connection type
	*/
	enum ConnectionType
	{
		CT_BLUETOOTH,					/** External Bluetooth connection */
		CT_WIFI,						/** External WiFi with access point connection */
		CT_TCPIP,						/** External TCP connection */
		CT_BLUETOOTHRADIO,				/** External Bluetooth radio connection */
		CT_USB,							/** External USB connection */
        CT_ONBOARD_SERIAL,				/** Onboard Serial connection */
        CT_EMPOWER,				        /** External EMPower connection */
		CT_INTERNAL,					/** internal connection */
		CT_INTERNAL_USB,				/** Internal USB connection */
		CT_INTERNAL_SERIAL,				/** Internal Serial connection */
		CT_INTERNAL_BLUETOOTHSOCKET,	/** Internal BluetoothSocket connection */
		CT_INTERNAL_TCPIP,				/** Internal TCP/IP connection */
		CT_INTERNAL_BLUETOOTHRADIO,		/** Internal BluetoothRadio connection */
		CT_INTERNAL_RADIO,				/** Internal Radio connection */
        CT_INTERNAL_BLUETOOTHRADIOBASE ,/** Internal BluetoothRadioBase connection */
        CT_INTERNAL_RADIOBASE,			/** Internal RadioBase connection */
        CT_INTERNAL_DEVICESERVER,		/** Internal Device server connection */
        CT_INTERNAL_SERIALVIAIP,		/** Internal Serial via TCP/IP connection */
	};
}
#endif
