#ifndef GSMMODEMDIALSTATUS_H_
#define GSMMODEMDIALSTATUS_H_

namespace SSI
{
	/*
	* Represents GSM Modem dial intermediate status.
	*/
	enum GSMModemDialStatus
	{
		/*
		* Preparing for dialing via modem.
		*/
		GSMModem_Prepare = 0,

		/*
		* Initlializing modem dial.
		*/
		GSMModem_Init,

		/*
		* Checking pin.
		*/
		GSMModem_CheckPin,

		/*
		* Checking network.
		*/
		GSMModem_CheckNetWork,

		/*
		* Dialing.
		*/
		GSMModem_Dialing,

		/*
		* Hanging up.
		*/
		GSMModem_HangingUp,

		/*
		* Connected.
		*/
		GSMModem_Connected
	};
}
#endif