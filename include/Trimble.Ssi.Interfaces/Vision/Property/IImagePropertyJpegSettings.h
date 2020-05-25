#ifndef IIMAGEPROPERTYJPEGSETTINGS_H_
#define IIMAGEPROPERTYJPEGSETTINGS_H_

#include "IImagingProperty.h"

namespace SSI
{
	/**
	* Represents an image property carrying information about the jpeg configuration settings
	*/
	class IImagePropertyJpegSettings : public IImagingProperty
	{
	public:
		virtual ~IImagePropertyJpegSettings();
	
		/**
		* Gets the quality between 0 and 1.
		* @return the jpeg quality
		*/
		virtual double getQuality() const = 0;
	};
}
#endif