#ifndef IIMAGEPROPERTYFLIP_H
#define IIMAGEPROPERTYFLIP_H
#include "IImagingProperty.h"
#include "Image/FlipType.h"

namespace SSI
{
	class IImagePropertyFlip : public IImagingProperty
	{
	public:
		virtual ~IImagePropertyFlip();
		virtual FlipType getFlipType() =0;
	};
}

#endif // IIMAGEPROPERTYFLIP_H
