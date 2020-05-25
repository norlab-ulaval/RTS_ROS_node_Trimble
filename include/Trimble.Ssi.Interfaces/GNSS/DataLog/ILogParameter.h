#ifndef ILOGPARAMETER_H_
#define ILOGPARAMETER_H_

#include "LogParameterType.h"

namespace SSI
{
	/**
	* Represents log parameter base interface
	*/
	class ILogParameter
	{
	public:
		virtual ~ILogParameter();
	
		/**
		* Gets the type of the log parameter.
		* @return The type of the log parameter.
		*/
		virtual LogParameterType getLogParameterType() =0;
	};
}
#endif