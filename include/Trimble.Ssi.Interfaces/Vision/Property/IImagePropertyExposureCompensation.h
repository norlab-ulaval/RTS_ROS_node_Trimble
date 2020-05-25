#ifndef IIMAGEPROPERTYEXSPOSURECOMPENSATION_H_
#define IIMAGEPROPERTYEXSPOSURECOMPENSATION_H_

#include "IImagingProperty.h"

namespace SSI
{
	/**
	* Represents an image property carrying information about the applied exposure compensation.
	*/
	class IImagePropertyExposureCompensation : public IImagingProperty
	{
	public:
		virtual ~IImagePropertyExposureCompensation();

		/**
		* Gets the exposure value.
		* @return the exposure value
		*/
		virtual double getExposureValue() const = 0;
	};
}
#endif
