#ifndef IAVAILABLEMEMORY_H_
#define IAVAILABLEMEMORY_H_

#include "ILogInfo.h"

namespace SSI
{
	/**
	* Interface for accessing available memory in the receiver.
	*/
	class IAvailableMemory: public ILogInfo
	{
	public:
		virtual ~IAvailableMemory();
	
		/**
		* Gets the bytes.
		* @return The bytes.
		*/
		virtual long long getBytes()=0;
	};
}
#endif