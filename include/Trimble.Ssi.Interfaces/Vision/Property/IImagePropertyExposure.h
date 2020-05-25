#ifndef IIMAGEPROPERTYEXPOSURE_H_
#define IIMAGEPROPERTYEXPOSURE_H_

#include "../Image/IExposure.h"
#include "IImagingProperty.h"

namespace SSI
{
	/**
	* Represents an image property carrying information about the exposure of the camera.
	*/
	class IImagePropertyExposure : public IImagingProperty
	{
	public:
		virtual ~IImagePropertyExposure();

		/**
		* Gets the milliseconds.
		*/
		virtual IExposure* getExposure() const = 0;
	};
}
#endif
