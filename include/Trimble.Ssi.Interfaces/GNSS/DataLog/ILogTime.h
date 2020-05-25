#ifndef ILOGTIME_H
#define ILOGTIME_H

#include "ILogInfo.h"

namespace SSI
{
	/**
	* Interface for accessing Logging Time.
	*/
	class ILogTime: public ILogInfo
	{
	public:
		virtual ~ILogTime();
	
		/**
		* Gets the time.
		* @return The time.
		*/
		virtual unsigned int getTime()=0;
	};
}
#endif