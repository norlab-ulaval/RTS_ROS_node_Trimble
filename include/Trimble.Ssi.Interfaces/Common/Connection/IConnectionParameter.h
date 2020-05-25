#ifndef ICONNECTIONPARAMETER_H_
#define ICONNECTIONPARAMETER_H_

#include "ConnectionParameterType.h"

namespace SSI
{
	/**
	* base class for connection parameters.
	* @see ConnectionParameterType
	* @see ISensor
	*/
	class IConnectionParameter
	{
	public:
		virtual ~IConnectionParameter();

		/**
		* get connection parameter type
		* @return the connection parameter type
		*/
		virtual ConnectionParameterType getConnectionParameterType() const = 0;
	};
}
#endif
