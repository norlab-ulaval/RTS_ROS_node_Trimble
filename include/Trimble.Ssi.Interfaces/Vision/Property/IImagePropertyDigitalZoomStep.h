#ifndef IIMAGEPROPERTYDIGITALZOOMSTEP_H
#define IIMAGEPROPERTYDIGITALZOOMSTEP_H
#include "IImagingProperty.h"

namespace SSI
{
	class IImagePropertyDigitalZoomStep : public IImagingProperty
	{
	public:
		virtual ~IImagePropertyDigitalZoomStep();

		/**
		* Get the zoom step
		* @return the zoom step
		*/
		virtual int getZoomStep() = 0;
	};
}

#endif // IIMAGEPROPERTYDIGITALZOOMSTEP_H
