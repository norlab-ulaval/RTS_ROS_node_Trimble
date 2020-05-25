#ifndef IFRAMEFULL_H
#define IFRAMEFULL_H
#include "IFrame.h"
#include "IFrameVerticalLimits.h"
#include "IFrameBounds.h"

namespace SSI
{
	/**
	* Any frame that defines the maximum angular area surrounding the instrument without horizontal limits.
	* @see Trimble.Ssi.Interfaces.Utilities.Frame.IFrame
	* @see Trimble.Ssi.Interfaces.Utilities.Frame.IFrameVerticalLimits
	* @see Trimble.Ssi.Interfaces.Utilities.Frame.IFrameBounds
	*/
	class IFrameFull : public virtual IFrame, public virtual IFrameVerticalLimits, public virtual IFrameBounds
	{
	public:
		virtual ~IFrameFull();
	};
}

#endif // IFRAMEFULL_H
