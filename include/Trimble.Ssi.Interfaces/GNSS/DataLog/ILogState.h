#ifndef ILOGSTATE_H
#define ILOGSTATE_H

#include "ILogInfo.h"
#include "LogActivityState.h"

namespace SSI
{
	/**
	* Interface for accessing Log state.
	*/
	class ILogState: public ILogInfo
	{
	public:
		virtual ~ILogState();

		/**
		* Gets the state of the log.
		* @return The state of the log.
		*/
		virtual LogActivityState getLogActivityState()=0;
	};
}
#endif