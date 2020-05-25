#ifndef ICONNECTIONPARAMETERPIN_H
#define ICONNECTIONPARAMETERPIN_H

#include "IConnectionParameter.h"
#include <string>

namespace  SSI {

	/**
	* Represents a connection parameter to handle personal identification number (PIN).
	* @see Trimble.Ssi.Connection.IConnectionParameter
	* @remark Configure the 4 digits PIN with the 2nd face display on the instrument.
	* @see ISensor
	*/
	class IConnectionParameterPin : public IConnectionParameter
	{
	public:
		virtual ~IConnectionParameterPin();
		ConnectionParameterType getConnectionParameterType() const;

		/**
		* Gets the personal identification number.
		* @return
		* Personal identification number.
		*/
		virtual std::string getPin()=0;
		/**
		* Sets the personal identification number.
		* @return
		* Personal identification number.
		*/
		virtual void setPin(std::string pin) = 0;
	};

}
#endif        //  #ifndef ICONNECTIONPARAMETERPIN_H
