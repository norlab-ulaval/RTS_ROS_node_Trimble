#ifndef ILOGINTERVAL_H
#define ILOGINTERVAL_H

#include "ILogInfo.h"

namespace SSI 
{
	/**
	* Interface for accessing configured logging interval.
	*/
	class ILogInterval : public ILogInfo
	{
	public:
		virtual ~ILogInterval(void);

		/**
		* Gets the interval
		* @return The interval.
		*/
		virtual double getInterval()=0;
	};
}
#endif