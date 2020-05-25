#ifndef IIMAGEPROPERTYCAMERASPECS_H_
#define IIMAGEPROPERTYCAMERASPECS_H_

#include "IImagingProperty.h"
#include "SpatialImaging/ICameraProperty.h"

namespace SSI
{
	/// <summary>
	/// Represents an image property carrying intrinsic camera information 
	/// </summary>
	class IImagePropertyCameraSpecs : public  IImagingProperty,public Trimble_Contracts::ICameraProperty //, ICameraProperty
	{
	public:
		virtual ~IImagePropertyCameraSpecs();
	};
}
#endif