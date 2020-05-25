#ifndef IIMAGEPROPERTYINTRINSIC_H_
#define IIMAGEPROPERTYINTRINSIC_H_

#include "IImagingProperty.h"
#include "SpatialImaging/IIntrinsicImageProperty.h"

namespace SSI
{
	/**
	* Represents an image property carrying intrinsic information about the camera.
	*/
	class IImagePropertyIntrinsic : public IImagingProperty,public Trimble_Contracts::IIntrinsicImageProperty
	{
	public:
		virtual ~IImagePropertyIntrinsic();
	};
}
#endif