#ifndef ICONNECTIONPARAMETERRADIOSETTINGS_H_
#define ICONNECTIONPARAMETERRADIOSETTINGS_H_

#include "IConnectionParameter.h"

namespace SSI
{
	/**
	* Represents connection parameter type for a radio connection.
	*/
	class IConnectionParameterRadioSettings : public IConnectionParameter
	{
	public:
		virtual ~IConnectionParameterRadioSettings();

		/**
		* get the connection parameter type
		* @return connection parameter type
		*/
		virtual ConnectionParameterType getConnectionParameterType() const;

		/**
		*Gets the channel.
		* @remarks
		*     Channels for single radio are between 1 and 30.
		*     Channels for radio as base are between 31 and 59.
		* @returns Channel used to connect.
		*/
		virtual int getChannel() const = 0;

		/**
		*Sets the channel.
		* @remarks
		*     Channels for single radio are between 1 and 30.
		*     Channels for radio as base are between 31 and 59.
		* @param channel Channel used to connect.
		*/
		virtual void setChannel(int channel) = 0;

		/**
		* Gets the channel maximum.
		* @return maximum channel id
		*/
		virtual int getChannelMaximum() const = 0;

		/**
		* Gets the channel minimum.
		* @return minimum channel id
		*/
		virtual int getChannelMinimum() const = 0;

		/**
		* Gets the network ID.
		* @remarks Valid values are 1 to 255.
		* @returns Network ID used to connect.
		*/
		virtual int getNetworkId() const = 0;

		/**
		* Sets the network ID.
		* @remarks Valid values are 1 to 255.
		* @param Network ID used to connect.
		*/
		virtual void setNetworkId(int networkId) = 0;

		/**
		* Gets the network id maximum.
		* @return maximum network id
		*/
		virtual int getNetworkIdMaximum() const = 0;

		/**
		* Gets the network id minimum.
		* @return minimum network id
		*/
		virtual int getNetworkIdMinimum() const = 0;
	};
}
#endif