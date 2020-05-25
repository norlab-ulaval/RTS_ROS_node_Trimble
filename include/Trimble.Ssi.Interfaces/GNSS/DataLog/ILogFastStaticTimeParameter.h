#ifndef ILOGFASTSTATICTIMEPARAMETER_H_
#define ILOGFASTSTATICTIMEPARAMETER_H_

#include "ILogParameter.h"

namespace SSI
{
	/**
	* Provides access to setter and getter for Log LogDuration Parameter.
	*/
	class ILogFastStaticTimeParameter: public ILogParameter
	{
	public:
		virtual ~ILogFastStaticTimeParameter();

		/**
		* Gets the time for logging with 4 Satellites
		* @return The time.
		*/
		virtual unsigned int getTime4SV()=0;

		/**
		* Sets the time for logging with 4 Satellites
		* @param time The time.
		*/
		virtual void setTime4SV(unsigned int time)=0;

		/**
		* Gets the time for logging with 5 Satellites
		* @return The time.
		*/
		virtual unsigned int getTime5SV()=0;

		/**
		* Sets the time for logging with 5 Satellites
		* @param time The time.
		*/
		virtual void setTime5SV(unsigned int time)=0;

		/**
		* Gets the time for logging with 6 Satellites
		* @return The time.
		*/
		virtual unsigned int getTime6SV()=0;

		/**
		* Sets the time for logging with 6 Satellites
		* @param time The time.
		*/
		virtual void setTime6SV(unsigned int time)=0;
	};
}
#endif