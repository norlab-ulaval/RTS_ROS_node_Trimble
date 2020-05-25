#ifndef LOGINFOCONTAINER_H_
#define LOGINFOCONTAINER_H_

#include "ILogInfo.h"
#include <vector>

namespace SSI
{
	/**
	* Provides access to logging information that were generated during data logging.
	* @see ISurveyLogSession
	*/
	class LogInfoContainer
	{
	public:
		/**
		* constructor.
		* @param std::vector<ILogInfo*> the observations
		*/
		LogInfoContainer(std::vector<ILogInfo*>& observations);
		LogInfoContainer();
		virtual ~LogInfoContainer();

		/**
		* get the observations.
		* @return the observations
		*/
		std::vector<ILogInfo*> getLogInfoList() const;

		LogInfoContainer(const LogInfoContainer& copyMe);
		LogInfoContainer& operator=(const LogInfoContainer&);
	private:
		std::vector<ILogInfo*> _logInfoList; /** observation list */
	};
}
#endif