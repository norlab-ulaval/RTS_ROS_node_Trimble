#ifndef IEXPOSUREMANUAL_H_
#define IEXPOSUREMANUAL_H_

#include "IExposure.h"

namespace SSI
{
	/**
	* Represents exposure settings for manual exposure regulation
	*/
	class IExposureManual : public IExposure
	{
	public:
		virtual ~IExposureManual();

		/**
		* Gets the min exposure milliseconds.
		* @return the min exposure in milliseconds
		*/
		virtual double getMinExposureMilliseconds() const = 0;

		/**
		* Gets the max exposure milliseconds.
		* @return the max exposure in milliseconds
		*/
		virtual double getMaxExposureMilliseconds() const = 0;

		/**
		* Gets the milliseconds.
		* @return The milliseconds.
		*/
		virtual double getMilliseconds() const = 0;

		/**
		* Sets the milliseconds.
		* @param milliseconds The milliseconds.
		*/
		virtual void setMilliseconds(double milliseconds) = 0;
	};
}
#endif