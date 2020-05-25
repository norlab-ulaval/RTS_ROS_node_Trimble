#ifndef IIMAGEPROPERTYAPERTURE_H_
#define IIMAGEPROPERTYAPERTURE_H_

#include "IImagingProperty.h"

namespace SSI
{
	/// <summary>
	/// Represents an image property carrying information about the cameras aperture.
	/// </summary>
	class IImagePropertyAperture : public IImagingProperty
	{
	public:
		virtual ~IImagePropertyAperture();
	
		/// <summary>
		/// Gets the focal number.
		/// </summary>
		virtual double getFocalNumber() const = 0;
	};
}
#endif