#ifndef IIMAGEPROPERTYOPTICALZOOMSTEP_H
#define IIMAGEPROPERTYOPTICALZOOMSTEP_H
#include "IImagingProperty.h"

namespace SSI
{
	class IImagePropertyOpticalZoomStep : public IImagingProperty
	{
	public:
		virtual ~IImagePropertyOpticalZoomStep();

		/**
		 * Get the zoom step
		 * @return the zoom step
		 */
		virtual int getZoomStep() = 0;
	};
	
}
#endif // IIMAGEPROPERTYOPTICALZOOMSTEP_H
