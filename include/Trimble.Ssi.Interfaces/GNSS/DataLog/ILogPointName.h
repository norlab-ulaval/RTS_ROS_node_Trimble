#ifndef ILOGPOINTNAME_H_
#define ILOGPOINTNAME_H_

#include "ILogInfo.h"
#include <string>

namespace SSI
{
	/**
	* Interface for accessing the point name.
	*/
	class ILogPointName: public ILogInfo
	{
	public:
		virtual ~ILogPointName();

		/**
		* Gets the name.
		* @return The name.
		*/
		virtual std::string getName()=0;
	};
}
#endif