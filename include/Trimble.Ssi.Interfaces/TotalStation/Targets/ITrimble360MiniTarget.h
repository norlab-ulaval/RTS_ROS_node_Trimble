#ifndef ITRIMBLE360MINITARGET_H_
#define ITRIMBLE360MINITARGET_H_

#include "IPrismIdTarget.h"

namespace SSI
{
	/** This interface represents the %Trimble 360° Mini target for the Trimble 5600.
	* Part.No. 571204312 , prism constant 2 mm.
	* @see ISsiTargets
	*/
	class ITrimble360MiniTarget : public IPrismIdTarget
	{
	public:
		virtual ~ITrimble360MiniTarget();
	};
}
#endif