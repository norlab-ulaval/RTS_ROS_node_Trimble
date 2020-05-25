#ifndef ILINKPARAMETERINTERNALINTERNETSETTINGS_H_
#define ILINKPARAMETERINTERNALINTERNETSETTINGS_H_

#include "ILinkParameter.h"
#include <string>

namespace SSI
{
	/*
	* Represents Link parameter Internal internet settings.
	*/
	class ILinkParameterInternalInternetSettings:public ILinkParameter
	{
	public:
		virtual ~ILinkParameterInternalInternetSettings();

		/*
		* Gets the  modem PIN.
		* @return internal modem PIN
		*/
		virtual const std::string& getPIN()const=0;

		/*
		* Sets the modem PIN.
		* @param PIN internal modem PIN
		*/
		virtual void setPIN(std::string PIN)=0;

		/*
		* Gets the APN.
		* @return data connection access point name
		*/
		virtual const std::string& getAPN()const=0;
	
		/*
		* Sets the APN.
		* @param APN data connection access point name
		*/
		virtual void setAPN(std::string APN)=0;

		/*
		* Gets the user.
		* @return data connection user
		*/
		virtual const std::string& getUser() const=0;

		/*
		* Sets the user.
		* @param user data connection
		*/
		virtual void setUser(std::string user)=0;

		/*
		* Gets the password.
		* @return data connection password
		*/
		virtual const std::string& getPassword() const=0;

		/*
		* Sets the password.
		* @param password data connection password
		*/
		virtual void setPassword(std::string password)=0;
	};
}
#endif