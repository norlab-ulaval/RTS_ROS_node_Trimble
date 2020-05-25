#ifndef ILOGSESSIONSTATE_H_
#define ILOGSESSIONSTATE_H_

#include "SessionState.h"
#include "ILogInfo.h"

namespace SSI
{
	/**
	* Interface for accessing Log Session State.
	*/
	class ILogSessionState: public ILogInfo
	{
	public:
		virtual ~ILogSessionState();
	
		/**
		* Gets the state of the session.
		* @return The state of the session.
		*/
		virtual SessionState getSessionState()=0;
	};
}
#endif