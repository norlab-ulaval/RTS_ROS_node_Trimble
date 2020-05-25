#ifndef IIMAGEPROPERTYCAPTURE_H_
#define IIMAGEPROPERTYCAPTURE_H_

#include "Property/ImagingPropertyType.h"
#include "Property/IImagingProperty.h"
#include "ICapture.h"

namespace SSI
{
	/**
	* Interface for all types of captured image properties.
	*/
	class IImagePropertyCapture : public ICapture
	{
		virtual ~IImagePropertyCapture();
	
		/**
		* Gets the time stamp.
		*/
		virtual long long getTimeStamp() const = 0;

		/**
		* Determines whether the specified type has property.
		* @param type The type.
		* @return <c>true</c> if the specified type has property; otherwise, <c>false</c>.
		*/
		virtual bool hasProperty(ImagingPropertyType type) = 0;

		/**
		* Gets the property.
		* @param type The type.
		*/
		virtual IImagingProperty* getProperty(ImagingPropertyType type) = 0;
	};
}
#endif