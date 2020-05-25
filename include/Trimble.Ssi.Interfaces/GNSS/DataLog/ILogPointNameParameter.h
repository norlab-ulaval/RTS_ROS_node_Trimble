#ifndef ILOGPOINTNAMEPARAMETER_H_
#define ILOGPOINTNAMEPARAMETER_H_

#include "ILogParameter.h"
#include <string>

namespace SSI
{
	/**
	* Provides access to setter and getter for Log Point name Parameter.
	*/
	class ILogPointNameParameter: public ILogParameter
	{
	public:
		virtual ~ILogPointNameParameter();
	
		/**
		* Gets the name.
		* @return The name.
		*/
		virtual std::string getName()=0;

		/**
		* Sets the name.
		* @param name The name.
		*/
		virtual void setName(std::string name)=0;
	};
}
#endif