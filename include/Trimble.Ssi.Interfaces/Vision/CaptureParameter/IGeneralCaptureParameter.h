#ifndef IGENERALCAPTUREPARAMETER_H_
#define IGENERALCAPTUREPARAMETER_H_

#include "IImageCaptureParameter.h"
#include "IPanoramicCaptureParameter.h"
#include "IVideoCaptureParameter.h"

namespace SSI
{
	/**
	* Represents a capture parameter for use with <see cref="ICamera"/>, <see cref="ICameraFeatureVideo"/> and <see cref="ICameraFeaturePanorama"/>.
	*/
	class IGeneralCaptureParameter : public IImageCaptureParameter, public IPanoramicCaptureParameter, public IVideoCaptureParameter
	{
	public:
		virtual ~IGeneralCaptureParameter();
	};
}
#endif