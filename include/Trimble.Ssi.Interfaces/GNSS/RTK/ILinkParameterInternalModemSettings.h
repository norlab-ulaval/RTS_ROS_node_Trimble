#ifndef ILINKPARAMETERINTERNALMODEMSETTINGS_H_
#define ILINKPARAMETERINTERNALMODEMSETTINGS_H_

#include "ILinkParameter.h"
#include <string>

namespace SSI
{
	/**
	* Represents Link parameter internal modem settings.
	* @see ISsiRtkSurvey
	*/
	class ILinkParameterInternalModemSettings:public ILinkParameter
	{
	public:
		virtual ~ILinkParameterInternalModemSettings();

		/**
		* Gets the modem PIN.
		* @return The modem PIN.
		*/
		virtual std::string getPin() const=0;

		/**
		* Sets the modem PIN.
		* @param pin The modem PIN.
		*/
		virtual void setPin(std::string pin)=0;
	};
}
#endif