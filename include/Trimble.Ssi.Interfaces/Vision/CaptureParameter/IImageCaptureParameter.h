#ifndef IIMAGECAPTUREPARAMETER_H_
#define IIMAGECAPTUREPARAMETER_H_

#include "ICaptureParameter.h"

namespace SSI
{
	/**
	* Represents a capture parameter used with <see cref="ICamera.CaptureImage()"/>.
	*/
	class IImageCaptureParameter : public virtual  ICaptureParameter
	{
	public:
		virtual ~IImageCaptureParameter();
	};
}
#endif