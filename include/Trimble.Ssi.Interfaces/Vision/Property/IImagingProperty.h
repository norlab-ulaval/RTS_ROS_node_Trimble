#ifndef IIMAGINGPROPERTY_H_
#define IIMAGINGPROPERTY_H_

#include "ImagingPropertyType.h"

namespace SSI
{
	/**
	* The base interface for image related properties
	*/
	class IImagingProperty
	{
	public:
		virtual ~IImagingProperty();
	
		/**
		* Gets the type of the image property.
		* @return The type of the image property.
		*/
		virtual ImagingPropertyType getImagingPropertyType() const = 0;

		/**
		 * Clone the image property
		 */
		virtual  IImagingProperty * clone() =0;
	};
}
#endif