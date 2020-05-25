#ifndef ILOGINFO_H_
#define ILOGINFO_H_

#include "LoggingInfoType.h"

namespace SSI
{
	/**
	* Reperesents base interface for accessing Logging Info.
	*/
	class ILogInfo
	{
	public:
		virtual ~ILogInfo();

		/**
		* Gets the type of the logging information.
		* @return The type of the logging information.
		*/
		virtual LoggingInfoType getLoggingInfoType()=0;
		virtual ILogInfo& clone() = 0;
	};
}
#endif