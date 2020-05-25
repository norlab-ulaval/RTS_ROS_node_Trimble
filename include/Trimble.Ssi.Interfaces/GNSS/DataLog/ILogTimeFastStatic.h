#ifndef ILOGTIMEFASTSTATIC_H_
#define ILOGTIMEFASTSTATIC_H_

#include "ILogInfo.h"

namespace SSI
{
	/**
	* Interface for accessing Fast Static Logging Time.
	*/
	class ILogTimeFastStatic: public ILogInfo
	{
	public:
		virtual ~ILogTimeFastStatic();
	
		/**
		* Gets the time for logging with 4 Satellites
		* @return The time.
		*/
		virtual unsigned int getTime4SV()=0;

		/**
		* Gets the time for logging with 5 Satellites
		* @return The time.
		*/
		virtual unsigned int getTime5SV()=0;

		/**
		* Gets the time for logging with 6 Satellites
		* @return The time.
		*/
		virtual unsigned int getTime6SV()=0;
	};
}
#endif