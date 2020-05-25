#ifndef IIMAGEPROPERTYINTRINSICIMAGE_H_
#define IIMAGEPROPERTYINTRINSICIMAGE_H_

#include "IImagingProperty.h"
#include "SpatialImaging/IIntrinsicCroppingProperty.h"

namespace SSI
{
	/**
	* Represents an image property carrying information about the applied cropping.
	*/
	class IImagePropertyIntrinsicImage : public IImagingProperty,public Trimble_Contracts::IIntrinsicCroppingProperty
	{
	public:
		virtual ~IImagePropertyIntrinsicImage();
	};
}
#endif