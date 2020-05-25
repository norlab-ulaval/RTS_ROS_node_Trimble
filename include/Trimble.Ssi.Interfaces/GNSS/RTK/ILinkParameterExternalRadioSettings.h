#ifndef ILINKPARAMETEREXTERNALRADIOSETTINGS_H_
#define ILINKPARAMETEREXTERNALRADIOSETTINGS_H_

#include "ILinkParameterRadioSettings.h"
#include "Parity.h"

namespace SSI
{
	/*
	* Represents link parameter External radio settings.
	*/
	class ILinkParameterExternalRadioSettings : public ILinkParameterRadioSettings
	{
	public:
		~ILinkParameterExternalRadioSettings();

		/*
		* Gets the port.
		* 
		* @return The port.
		*/
		virtual int getPort() const=0;

		/*
		* Sets the port.
		* 
		* @param port The port.
		*/
		virtual void setPort(int port)=0;

		/*
		* Gets the baud rate.
		* 
		* @return The baud rate.
		*/
		virtual int getBaudRate() const=0;

		/*
		* Sets the baud rate.
		* 
		* @param baudrate The baud rate.
		*/
		virtual void setBaudRate(int baudrate)=0;

		/*
		* Gets the data bits.
		* 
		* @return The data bits.
		*/
		virtual int getDataBits() const=0;

		/*
		* Sets the data bits.
		* 
		* @param databits The data bits.
		*/
		virtual void setDataBits(int databits)=0;

		/*
		* Gets the stop bits.
		* 
		* @return The stop bits.
		*/
		virtual int getStopBits() const=0;

		/*
		* Sets the stop bits.
		* 
		* @param stopbits The stop bits.
		*/
		virtual void setStopBits(int stopbits)=0;

		/*
		* Gets the parity.
		* 
		* @return The parity.
		*/
		virtual Parity getParity() const=0;
	
		/*
		* Sets the parity.
		* 
		* @param parity The parity.
		*/
		virtual void setParity(Parity parity)=0;
	};
}
#endif