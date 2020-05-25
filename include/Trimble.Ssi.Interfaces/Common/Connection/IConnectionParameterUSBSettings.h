#ifndef ICONNECTIONPARAMETERUSBSETTINGS_H_
#define ICONNECTIONPARAMETERUSBSETTINGS_H_

#include "IConnectionParameterExternalSettings.h"

namespace SSI
{
	/**
	* Represents connection parameter type for a USB connection.
	*/
	class IConnectionParameterUSBSettings : public IConnectionParameterExternalSettings
	{
	public:
		virtual ~IConnectionParameterUSBSettings();

		/**
		* get the connection parameter type
		* @return connection parameter type
		*/
		ConnectionParameterType getConnectionParameterType() const;

		/**
		* Get the USB VendorId
		* @return The VendorId to be used
		*/
		virtual int getVendorId() const = 0;

		/**
		* Set the USB VendorId
		* @param vendorId The VendorId to be used
		*/
		virtual void setVendorId(int vendorId) = 0;

		/**
		* Get the USB ProductId
		* @return The ProductId to be used
		*/
		virtual int getProductId() const = 0;

		/**
		* Set the USB ProductId
		* @param productId The ProductId to be used
		*/
		virtual void setProductId(int productId) = 0;
	};
}
#endif
