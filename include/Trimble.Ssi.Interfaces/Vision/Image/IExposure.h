#ifndef IEXPOSURE_H_
#define IEXPOSURE_H_

#include "ExposureType.h"

namespace SSI
{
	/**
	* Represents the base class of exposure settings
	*/
	class IExposure
	{
	public:
		virtual ~IExposure();
	
		/**
		* Gets the type of the exposure.
		* @return The type of the exposure.
		*/
		virtual ExposureType getExposureType() const = 0;
	};
}
#endif