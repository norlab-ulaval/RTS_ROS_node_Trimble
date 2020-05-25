#ifndef IRADIOCONFIGURATIONTS_H_
#define IRADIOCONFIGURATIONTS_H_

#include "RadioMode.h"

namespace SSI
{
	/**
	* Provides members to basic information about Radio configuration of an instrument.
	*/
	class IRadioConfigurationTS
	{
	public:
		virtual ~IRadioConfigurationTS(void);

		/** 
		* Set the Channel value.
		* @param int the Channel value to set
		*/
		virtual void SetChannel(int nChannel) = 0;

		/**
		* Gets the Channel value
		* @return int the Channel value.
		*/
		virtual int GetChannel() = 0;

		/**	
		* Gets the Channel minimum
		* @return int the Channel minimum value.
		*/
		virtual int GetChannelMin() = 0;

		/**
		* Gets the Channel maximum
		* @return int the Channel maximum value.
		*/
		virtual int GetChannelMax() = 0;

		/** 
		* Set the Network id value.
		* @param int the NetworkID value to set
		*/
		virtual void SetNetworkId(int nNetworkId) = 0;

		/**
		* Gets the NetworkID value
		* @return int the NetworkID value.
		*/
		virtual int GetNetworkId() = 0;

		/**
		* Gets the NetworkID minimum value
		* @return int the NetworkID minimum value.
		*/
		virtual int GetNetworkIdMin() = 0;

		/**
		* Gets the NetworkID maximum
		* @return int the NetworkID maximum value.
		*/
		virtual int GetNetworkIdMax() = 0;

		/**
		* Get current RadioMode is set.
		* @return mode the RadioMode
		*/
		virtual RadioMode GetRadioMode() = 0;
	};
}
#endif