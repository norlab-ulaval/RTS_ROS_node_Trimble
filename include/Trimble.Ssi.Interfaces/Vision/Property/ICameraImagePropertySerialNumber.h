#ifndef ICAMERAIMAGEPROPETYSERIALNUMBER_H_
#define ICAMERAIMAGEPROPETYSERIALNUMBER_H_

#include "IImagingProperty.h"
#include <string>

namespace SSI
{
	/**
	* Represents an image property carrying information about the Serial Number
	*/
	class ICameraImagePropertySerialNumber : public IImagingProperty
    {
	public:
		virtual ~ICameraImagePropertySerialNumber();
	
		/**
		* Gets the serial number.
		* @return The serial number.
		*/
		virtual std::string serialNumber() const = 0;
	};
}
#endif