#ifndef ICATEYE360DEGREETARGET_H_
#define ICATEYE360DEGREETARGET_H_

#include "IPrismWithSizeTarget.h"

namespace SSI
{
	/**
	* Represents a 360 degree target made of cateye stripes.
	* <seealso cref="ISsiTargets"/>
	*/
	class ICateye360DegreeTarget : public IPrismWithSizeTarget
	{
	public:
		virtual ~ICateye360DegreeTarget();
	};
}
#endif