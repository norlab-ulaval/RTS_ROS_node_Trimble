#ifndef LINKPARAMETERTYPE_H_
#define LINKPARAMETERTYPE_H_

namespace SSI
{
	/* Represents correction link parameter.
	* @remarks To get an enumeration of supported LinkParameterType values, use ISsiRtkSurvey.ListSupportedLinkParameterTypes
	*/
	enum LinkParameterType
	{
		/*
		* Link is established via internal internet.
		*/
		LinkParameterType_InternalInternet,

		/*
		* Link is established via controller internet.
		*/
		LinkParameterType_ControllerInternet,

		/*
		* Link is established via internal modem.
		*/
		LinkParameterType_InternalModem,

		/*
		* Link is established via controller modem.
		*/
		LinkParameterType_ControllerModem,

		/*
		* Link is established via bluetooth connected modem.
		*/
		LinkParameterType_BluetoothModem,

		/*
		* Link is established via internal radio.
		*/
		LinkParameterType_InternalRadio,

		/*
		* Link is established via external radio.
		*/
		LinkParameterType_ExternalRadio,

		/*
		* Link is established via internal Bluetooth.
		*/
		LinkParameterType_InternalBluetooth,

		/*
		* Link is established via RTX Satellite.
		*/
		LinkParameterType_RTXSatellite,

		/*
		* Link is established via SBAS Satellite.
		*/
		LinkParameterType_SBASSatellite
	};
}
#endif