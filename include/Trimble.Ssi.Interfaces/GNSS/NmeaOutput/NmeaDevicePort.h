#ifndef NMEADEVICEPORT_H
#define NMEADEVICEPORT_H

namespace SSI
{
	/**
	*  Displaying the Nmea Device Ports.
	*/
	enum NmeaDevicePort
	{
		/**
		*  The serial port 1
		*/
		Nmea_SerialOne,

		/**
		*  The serial port 2
		*/
		Nmea_SerialTwo,

		/**
		*  The bluetooth port 1
		*/
		Nmea_BluetoothOne,

		/**
		*  The bluetooth port 2
		*/
		Nmea_BluetoothTwo,

		/**
		*  The bluetooth port 3
		*/
		Nmea_BluetoothThree,

        /**
		*  The Controller event
		*/
		Nmea_Controller
	};
}
#endif