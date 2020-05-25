#ifndef ILOGSTARTTIMEPARAMETER_H
#define ILOGSTARTTIMEPARAMETER_H

#include "ILogParameter.h"

namespace SSI
{
	/**
	* Provides access to setter and getter for Log Start time Parameter.
	*/
	class ILogStartTimeParameter: public ILogParameter
	{
	public:
		virtual ~ILogStartTimeParameter();

		/**
		* Gets the log start time.
		* @return The log start time.
		*/
		virtual long long getStartTime()=0;
	
		/**
		* Sets the log start time.
		* @param startTime The log start time.
		*/
		virtual void setStartTime(long long startTime)=0;
	};
}
#endif