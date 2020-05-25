#ifndef ILOGANTENNA_H
#define ILOGANTENNA_H

#include "ILogInfo.h"
#include "Antenna/IAntenna.h"

namespace SSI
{
	/**
	* Interface for accessing antenna parameter.
	*/
	class ILogAntenna : public ILogInfo
	{
	public:
		virtual ~ILogAntenna(void);

		/**
		* Gets the antenna configuration.
		* @return The antenna configuration.
		*/
		virtual IAntenna& getAntenna()=0;
	};
}
#endif