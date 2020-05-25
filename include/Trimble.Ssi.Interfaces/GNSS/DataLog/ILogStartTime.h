#ifndef ILOGSTARTTIME_H_
#define ILOGSTARTTIME_H_

#include "ILogInfo.h"

namespace SSI
{
	/**
	* Interface for accessing Log Start time.
	*/
	class ILogStartTime: public ILogInfo
	{
	public:
		virtual ~ILogStartTime();
	
		/**
		* Gets the start time.
		* @return The start time.
		*/
		virtual long long getStartTime()=0;
	};
}
#endif