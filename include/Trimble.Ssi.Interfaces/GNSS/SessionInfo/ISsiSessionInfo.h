#ifndef ISSISESSIONINFO_H_
#define ISSISESSIONINFO_H_

#include "ISsiInterface.h"
#include "DataLog/ILogSessionName.h"
#include "SessionListContainer.h"

namespace SSI 
{
	class ISsiSessionInfo :  public ISsiInterface
	{
	public:
		virtual ~ISsiSessionInfo(void);

		/**
		* Deletes the session from receiver.
		* @param sessionName The session name
		*/
		virtual void deleteSession(ILogSessionName & sessionName)=0;

		/**
		* Sends the session list update request.
		*/
		virtual const SessionListContainer& readSessionList()=0;
	};
}
#endif