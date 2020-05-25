#ifndef ICORRECTIONDATASOURCEBLUETOOTHROVERSETTINGS_H_
#define ICORRECTIONDATASOURCEBLUETOOTHROVERSETTINGS_H_

#include "BluetoothDeviceListContainer.h"
#include "ICorrectionDataSourceBluetoothSettings.h"

namespace SSI
{
	/**
	*  Represents correction data source Bluetooth rover settings.
	*  @see ISsiRTKSurvey
	*/
	class ICorrectionDataSourceBluetoothRoverSettings : public ICorrectionDataSourceBluetoothSettings
	{
	public:
		virtual ~ICorrectionDataSourceBluetoothRoverSettings();
		
		/**
		* Sends the Bluetooth device list update request.
		* @return Container with Bluetooth device infos
		*/
		virtual const BluetoothDeviceListContainer& loadBluetoothDevices() const = 0;

		/*
		* Reconnects the Bluetooth device.
		*/
		virtual void reconnectBluetoothDevice() = 0;

		/**
		* Gets the Bluetooth address.
		* @return The Bluetooth address.
		*/
		virtual const std::string& getBluetoothAddress() const = 0;

		/**
		* Sets the Bluetooth address.
		* @param address The Bluetooth address.
		*/
		virtual void setBluetoothAddress(std::string address) = 0;

		/**
		* Gets the index of the base station.
		* @return The index of the base station.
		* @remarks Negative value will match any base station index
		*/
		virtual short getBaseStationIndex() const = 0;

		/**
		* Sets the index of the base station.
		* @param baseStationIndex The index of the base station.
		* @remarks Negative value will match any base station index
		*/
		virtual void setBaseStationIndex(short baseStationIndex) = 0;
	};
}
#endif