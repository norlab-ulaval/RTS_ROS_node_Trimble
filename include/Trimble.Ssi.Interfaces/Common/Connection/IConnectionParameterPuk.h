#ifndef ICONNECTIONPARAMETERPUK_H
#define ICONNECTIONPARAMETERPUK_H
#include <string>
#include "IConnectionParameter.h"

namespace SSI {
	/**
	* Represents a connection parameter to handle personal unblocking key (PUK).
	* @see Trimble.Ssi.Connection.IConnectionParameter
	* @see ISensor
	*/
	class IConnectionParameterPuk : public IConnectionParameter
	{
	public:
		virtual ~IConnectionParameterPuk();
		ConnectionParameterType getConnectionParameterType() const;

		/**
		* Gets the personal unblocking key.
		* @return
		* Personal unblocking key.
		*
		*/
		virtual std::string getPuk() = 0;

		/**
		* Sets the personal unblocking key.
		* @return
		* Personal unblocking key.
		*
		*/
		virtual void setPuk(std::string puk) = 0;
	};

}
#endif        //  #ifndef ICONNECTIONPARAMETERPUK_H
