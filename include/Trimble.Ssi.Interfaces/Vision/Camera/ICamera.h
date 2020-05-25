#ifndef ICAMERA_H_
#define ICAMERA_H_

#include "CameraInformation.h"
#include "../Property/IImagingProperty.h"
#include "ICameraFeature.h"

namespace SSI
{
	/**
	* The ICamera interface provides access to a camera that capture images.
	*/
	class ICamera
	{
	public:
		virtual ~ICamera();
	
		/**
		* Gets the identifier of this camera. Passing this identifier to.
		* @return the camera info
		*/
		virtual CameraInformation getCameraInfo() const = 0;

		/**
		* Determines whether the camera has the property, defined by its type.
		* @param type The type.
		* @return <c>true</c> if the camera has the property; otherwise, <c>false</c>.
		*/
		virtual bool hasProperty(ImagingPropertyType type) const = 0;

		/**
		* Gets the property defined by its type.
		* @param type The type.
		* @return The <see cref="ICameraProperty" /> of the requested type.
		*/
		virtual IImagingProperty* getProperty(ImagingPropertyType type) const = 0;

		/**
		* Determines whether the camera has the camera feature of the given type.
		* @param type The type.
		* @return <c>true</c> if the camera has feature; otherwise, <c>false</c>.
		*/
		virtual bool hasFeature(CameraFeatureType type) const = 0;

		/**
		* Gets the feature.
		* @param type The type.
		* @return The <see cref="ICameraFeature"/> of the requested type
		*/
		virtual ICameraFeature* getFeature(CameraFeatureType type) const = 0;
	};
}
#endif