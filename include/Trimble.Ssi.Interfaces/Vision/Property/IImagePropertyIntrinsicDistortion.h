#ifndef IIMAGEPROPERTYINTRINSICDISTORTION_H_
#define IIMAGEPROPERTYINTRINSICDISTORTION_H_

#include "IImagingProperty.h"
#include "SpatialImaging/LensType.h"
#include "SpatialImaging/IIntrinsicDistortionImageProperty.h"

namespace SSI
{
	/**
	* Represents an image property carrying information about the distortion of the image.
	*/
	class IImagePropertyIntrinsicDistortion : public IImagingProperty,public Trimble_Contracts::IIntrinsicDistortionImageProperty
	{
	public:
		virtual ~IImagePropertyIntrinsicDistortion();
	};
}
#endif