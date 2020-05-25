#ifndef IPANORAMICCAPTUREPARAMETER_H_
#define IPANORAMICCAPTUREPARAMETER_H_

#include "ICaptureParameter.h"

namespace SSI
{
	/**
	* Represents a capture parameter used by <see cref="ICameraFeaturePanorama.StartPanorama"/>.
	*/
	class IPanoramicCaptureParameter : public virtual ICaptureParameter
	{
	public:
		virtual ~IPanoramicCaptureParameter();
	};
}
#endif