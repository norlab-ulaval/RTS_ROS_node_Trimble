#ifndef ILOGINTERVALPARAMETER_H_
#define ILOGINTERVALPARAMETER_H_

#include "ILogParameter.h"

namespace SSI
{
	/**
	* Provides access to setter and getter for Log Interval Parameter.
	*/
	class ILogIntervalParameter: public ILogParameter
	{
	public:
		virtual ~ILogIntervalParameter();

		/**
		* Gets the interval.
		* @return The interval.
		*/
		virtual double getInterval()=0;
	
		/**
		* Sets the interval.
		* @param interval The interval.
		*/
		virtual void setInterval(double interval)=0;
	};
}
#endif