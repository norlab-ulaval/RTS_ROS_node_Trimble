#ifndef IIMAGEPROPERTYEXTRINSICTELESCOPERELATIVETOINSTRUMENT_H_
#define IIMAGEPROPERTYEXTRINSICTELESCOPERELATIVETOINSTRUMENT_H_

#include "IImagingProperty.h"
#include "SpatialImaging/IExtrinsicTelescopeRelativeToInstrumentImageProperty.h"

namespace SSI
{
	/**
	* Represents an image property carrying relative orientation and translation between the telescope and the instrument.
	*/
	class IImagePropertyExtrinsicTelescopeRelativeToInstrument : public IImagingProperty,public Trimble_Contracts::IExtrinsicTelescopeRelativeToInstrumentImageProperty
	{
	public:
		~IImagePropertyExtrinsicTelescopeRelativeToInstrument();

		/**
		* Gets the type of the image property.
		* @return The type of the image property.
		*/
		virtual ImagingPropertyType getImagingPropertyType() const = 0;
	};
}
#endif