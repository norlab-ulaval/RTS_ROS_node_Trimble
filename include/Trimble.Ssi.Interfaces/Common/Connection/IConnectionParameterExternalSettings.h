#ifndef ICONNECTIONPARAMETEREXTERNALSETTINGS_H_
#define ICONNECTIONPARAMETEREXTERNALSETTINGS_H_

#include "IConnectionParameter.h"
#include "Connection/ICommunicator.h"

namespace SSI
{
	/**
	* Represents connection paramters for External settings
	*/
	class IConnectionParameterExternalSettings : public IConnectionParameter
	{
	public:
		virtual ~IConnectionParameterExternalSettings();

		/**
		* get the communicator
		* @return the communicator
		*/
		virtual Common::ICommunicator& getCommunicator() const = 0;

		/**
		* set the communicator
		* @param communicator the communicator
		*/
		virtual void setCommunicator(Common::ICommunicator& communicator) = 0;
	};
}
#endif