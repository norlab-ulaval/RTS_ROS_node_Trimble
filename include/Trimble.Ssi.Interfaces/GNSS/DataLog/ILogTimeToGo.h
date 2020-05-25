#ifndef ILOGTIMETOGO_H
#define ILOGTIMETOGO_H

#include "ILogInfo.h"

namespace SSI
{
	/**
	* Interface for accessing Log Time To Go.
	*/
	class ILogTimeToGo: public ILogInfo
	{
	public:
		virtual ~ILogTimeToGo();
	
		/**
		* Gets the time.
		* @return The time.
		*/
		virtual int getTime()=0;
	};
}
#endif