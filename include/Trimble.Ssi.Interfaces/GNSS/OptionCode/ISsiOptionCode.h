#ifndef ISSIOPTIONCODE_H
#define ISSIOPTIONCODE_H

#include "ISsiInterface.h"

namespace SSI
{
	/**
	* Provides methods to install option codes on the connected receiver.
	*/
	class ISsiOptionCode : public ISsiInterface
	{
	public:
		virtual ~ISsiOptionCode();
	
		/**
		* Sends an option code to the connected receiver.
		*
		* @param code The code which gets sent to the receiver.
		* @remarks Reconnect to the receiver before using a feature relying on the given code.
		*/
		virtual void installOptionCode(const char* code) = 0;
	};
}
#endif