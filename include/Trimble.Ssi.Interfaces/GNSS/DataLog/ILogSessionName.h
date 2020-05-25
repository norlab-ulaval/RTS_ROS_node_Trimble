#ifndef ILOGSESSIONNAME_H_
#define ILOGSESSIONNAME_H_

#include "ILogInfo.h"
#include <string>

namespace SSI
{
	/**
	* Interface for accessing the session name.
	*/
	class ILogSessionName: public ILogInfo
	{
	public:
		virtual ~ILogSessionName();

		/**
		* Gets the name.
		* @return The name.
		*/
		virtual std::string getName()=0;
	};
}
#endif