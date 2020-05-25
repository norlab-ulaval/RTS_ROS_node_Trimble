#ifndef BLUETOOTHDEVICELISTCONTAINER_H_
#define BLUETOOTHDEVICELISTCONTAINER_H_

#include "BluetoothDevice.h"
#include <vector>

namespace SSI
{
	/**
	* Provides access to Bluetooth device informations.
	*/
	class BluetoothDeviceListContainer
	{
	public:
		/**
		* constructor.
		* @param std::vector<BluetoothDevice*> the bluetoothDeviceLists
		*/
		BluetoothDeviceListContainer(std::vector<BluetoothDevice*>& bluetoothDeviceLists);
		BluetoothDeviceListContainer();
		virtual ~BluetoothDeviceListContainer();

		/**
		* get the bluetoothDeviceLists.
		* @return the bluetoothDeviceLists
		*/
		virtual std::vector<BluetoothDevice*> getList() const;

		BluetoothDeviceListContainer(const BluetoothDeviceListContainer& copyMe);

		BluetoothDeviceListContainer& operator=(const BluetoothDeviceListContainer&);

		void addBluetoothDevice(BluetoothDevice* BluetoothDevice);

		void clearBluetoothDeviceList();
	protected:
		std::vector<BluetoothDevice*> _bluetoothDeviceLists; /** bluetoothDeviceLists list */
	};
}
#endif