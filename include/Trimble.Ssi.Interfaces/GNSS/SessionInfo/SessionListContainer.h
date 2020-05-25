#ifndef SESSIONLISTCONTAINER_H_
#define SESSIONLISTCONTAINER_H_

#include "DataLog/LogInfoContainer.h"

namespace SSI
{
	class SessionListContainer
	{
	public:
		SessionListContainer(std::vector<LogInfoContainer*>& sessionInfoList);
		SessionListContainer();
		~SessionListContainer(void);
		std::vector<LogInfoContainer*> getSessionInfo() const;
		SessionListContainer(const SessionListContainer& copyMe);
		SessionListContainer& operator=(const SessionListContainer&);
		void clearList();
		void addLogInfo(LogInfoContainer* logInfo);
	private:
		std::vector<LogInfoContainer*> _sessionInfoList;
	};
}
#endif