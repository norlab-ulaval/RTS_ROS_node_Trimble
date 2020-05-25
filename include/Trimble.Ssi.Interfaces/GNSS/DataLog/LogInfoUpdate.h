#ifndef LOGINFOUPDATE_H_
#define LOGINFOUPDATE_H_

#include  "LogInfoContainer.h"

namespace SSI
{
	/*
	* Provides data for the Positioning Update.
	*/
	class LogInfoUpdate
	{
	public:
		/*
		* Initializes a new instance of the LogInfoUpdate
		*/
		LogInfoUpdate(LogInfoContainer& observations);

		/*Gets the observations.
		* @return LogInfoContainer&
		*/
		const LogInfoContainer& getLogInfoContainer() const;
	private:
		LogInfoUpdate();
		LogInfoUpdate(const LogInfoUpdate& copyMe);
		LogInfoUpdate& operator=(const LogInfoUpdate&);
		LogInfoContainer _logInfoContainer;
	};
}
#endif