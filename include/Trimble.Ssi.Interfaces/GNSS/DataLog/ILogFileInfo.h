#ifndef ILOGFILEINFO_H_
#define ILOGFILEINFO_H_

#include "ILogInfo.h"
#include "Files/ReceiverFileInfo.h"

namespace SSI
{
	/**
	* Interface for accessing Log file.
	*/
	class ILogFileInfo: public ILogInfo
	{
	public:
		virtual ~ILogFileInfo();
	
		/**
		* Gets the receiver file.
		* @return The receiver file.
		*/
		virtual ReceiverFileInfo getReceiverFileInfo()=0;
	};
}
#endif