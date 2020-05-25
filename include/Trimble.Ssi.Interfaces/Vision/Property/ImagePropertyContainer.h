#ifndef IMAGEPROPERTYCONTAINER_H_
#define IMAGEPROPERTYCONTAINER_H_

#include "IImagingProperty.h"

#include <vector>

namespace SSI
{
	/** 
	* the container for ImageProperty
	*/
	class ImagePropertyContainer
	{
	public:
		ImagePropertyContainer();
		virtual ~ImagePropertyContainer();

		/**
		* list the supported property types.
		* @return supported property type list.
		*/
		std::vector<ImagingPropertyType> listSupportedPropertyTypes() const;

		/**
		* Determines whether the specified type has property.
		* @param type The type.
		* @return <c>true</c> if the specified type has property; otherwise, <c>false</c>.
		*/
		bool hasProperty(ImagingPropertyType type) const;

		/**
		* Gets the property.
		* @param type The type.
		* @return the image property
		*/
		IImagingProperty* getProperty(ImagingPropertyType type) const;

		/**
		* Adds the image property.
		* @param imageProperty The image property.
		*/
		void addProperty(IImagingProperty& imageProperty);
	private:
		ImagePropertyContainer& operator=(const ImagePropertyContainer&);
		ImagePropertyContainer(const ImagePropertyContainer&);

		std::vector<IImagingProperty*> _imagePropertys;
	};
}
#endif