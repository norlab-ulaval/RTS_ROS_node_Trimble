#ifndef IIMAGEPROPERTYEXTRINSICCAMERARELATIVETOTELESCOPE_H_
#define IIMAGEPROPERTYEXTRINSICCAMERARELATIVETOTELESCOPE_H_

#include "IImagingProperty.h"
#include "SpatialImaging/IExtrinsicCameraRelativeToTelescopeImageProperty.h"

namespace SSI
{
	/**
	* Represents an image property carrying relative orientation and translation between the camera and the telescope
	*/
	class IImagePropertyExtrinsicCameraRelativeToTelescope : public IImagingProperty, public Trimble_Contracts::IExtrinsicCameraRelativeToTelescopeImageProperty
	{
	public:
		~IImagePropertyExtrinsicCameraRelativeToTelescope();
	
		/**
		* Gets the type of the image property.
		* @return The type of the image property.
		*/
		virtual ImagingPropertyType getImagingPropertyType() const = 0;
	};
}
#endif