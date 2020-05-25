#ifndef ILOGPOINTCODEPARAMETER_H_
#define ILOGPOINTCODEPARAMETER_H_

#include "ILogParameter.h"
#include <string>

namespace SSI
{
	/**
	* Provides access to setter and getter for Log Point code Parameter.
	*/
	class ILogPointCodeParameter : public ILogParameter
	{
	public:
		virtual ~ILogPointCodeParameter();
	
		/**
		* Getsthe code.
		* @return The code.
		*/
		virtual std::string getCode()=0;

		/**
		* Sets the code.
		* @param code The code.
		*/
		virtual void setCode(std::string code)=0;
	};
}
#endif