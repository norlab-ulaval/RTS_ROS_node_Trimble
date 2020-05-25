#ifndef ICONNECTIONPARAMETERSERIALNUMBER_H
#define ICONNECTIONPARAMETERSERIALNUMBER_H
#include <string>
#include "IConnectionParameter.h"

namespace SSI
{
	/**
	* Represents a connection parameter to handle serial numbers.
	* @remark It is used to connect to an instrument with its specified serial number.
	* @see Trimble.Ssi.Connection.IConnectionParameter
	* @see ISensor
	*/
	class IConnectionParameterSerialNumber : public IConnectionParameter
	{
	public:
		virtual ~IConnectionParameterSerialNumber();
		ConnectionParameterType getConnectionParameterType() const;

		/**
		* Gets the serial number.
		* @return
		* The serial number.
		*/
		virtual std::string getSerialNumber() = 0;

		/**
		* Sets the serial number.
		* @return
		* The serial number.
		*/
		virtual void setSerialNumber(std::string serialNumber) = 0;
	};
}
#endif        //  #ifndef ICONNECTIONPARAMETERSERIALNUMBER_H
