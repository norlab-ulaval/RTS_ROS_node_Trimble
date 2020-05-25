#ifndef ILOGDURATIONPARAMETER_H_
#define ILOGDURATIONPARAMETER_H_

#include "ILogParameter.h"

namespace SSI
{
	/**
	* Provides access to setter and getter for Log LogDuration Parameter.
	*/
	class ILogDurationParameter: public ILogParameter
	{
	public:
		virtual ~ILogDurationParameter();

		/**
		* Gets the duration.
		* @return The duration.
		*/
		virtual unsigned int getDuration()=0;

		/**
		* Sets the duration.
		* @param duration The duration.
		*/
		virtual void setDuration(unsigned int duration)=0;
	};
}
#endif