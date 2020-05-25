#ifndef BLUETOOTHDEVICE_H_
#define BLUETOOTHDEVICE_H_

#include <string>

namespace SSI
{
	/**
	* Represents a Bluetooth device instance.
	*/
	class BluetoothDevice
	{
	public:
		BluetoothDevice(std::string name, std::string address);

		/*
		* Initializes a new instance of the BluetoothDevice
		* @param BluetoothDevice&
		*/
		BluetoothDevice(const BluetoothDevice& assignMe);

		/**
		* Gets the Bluetooth device display name.
		* @return The name of the Bluetooth device.
		*/
		std::string getName();

		/**
		* Gets the address of the Bluetooth device.
		* @return The address of the Bluetooth device.
		*/
		std::string getAddress();


		BluetoothDevice& clone();
		BluetoothDevice& operator=(const BluetoothDevice& assignMe);
	private:
		std::string _name;
		std::string _address;
	};
}
#endif