#ifndef IVIDEOCAPTUREPARAMETER_H_
#define IVIDEOCAPTUREPARAMETER_H_

#include "ICaptureParameter.h"

namespace SSI
{
	/**
	* Represents a capture parameter used for <see cref="ICameraFeatureVideo.StartVideo"/> or <see cref="ICameraFeatureVideo.ChangeVideo"/>.
	*/
	class IVideoCaptureParameter : public virtual ICaptureParameter
	{
	public:
		virtual ~IVideoCaptureParameter();
	};
}
#endif