#ifndef ICORRECTIONDATASOURCEGSMBASESETTINGS_H_
#define ICORRECTIONDATASOURCEGSMBASESETTINGS_H_

#include "ICorrectionDataSourceAdvanced.h"
#include "IDialInStatusListener.h"
#include <string>

namespace SSI
{
	/**
	* Represents base Correction data source GSM settings.
	*/
	class ICorrectionDataSourceGSMBaseSettings: public virtual ICorrectionDataSourceAdvanced
	{
	public:
		virtual ~ICorrectionDataSourceGSMBaseSettings();

		/**
		* Gets the dial in initialization command.
		* @return The dial in initialization command.
		*/
		virtual std::string getDialInitCommand() const=0;

		/**
		* Sets the dial in initialization command.
		* @param dialInitCommand The dial in initialization command.
		*/
		virtual void setDialInitCommand(std::string dialInitCommand)=0;

		/**
		* Gets the dial in command.
		* @return The dial in command.
		*/
		virtual std::string getDialCommand() const=0;

		/**
		* Sets the dial in command.
		* @param dialCommand The dial in command.
		*/
		virtual void setDialCommand(std::string dialCommand)=0;

		/**
		* Gets the dial in number.
		* @return The dial in number.
		*/
		virtual std::string getDialInNumber() const=0;

		/**
		* Sets the dial in number.
		* @param dialInNumber The dial in number.
		*/
		virtual void setDialInNumber(std::string dialInNumber)=0;

		/**
		* register a listener for listening GSM Dial in status.
		* @param IDialInStatusListener to listen
		*/
		virtual void addDialInStatusListener(IDialInStatusListener& listener) = 0;

		/**
		* register a listener for listening GSM Dial in status.
		* @param IDialInStatusListener to listen
		*/
		virtual void removeDialInStatusListener(IDialInStatusListener& listener) = 0;
	};
}
#endif