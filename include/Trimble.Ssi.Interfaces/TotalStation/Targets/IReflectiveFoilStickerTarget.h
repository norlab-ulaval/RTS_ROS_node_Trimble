#ifndef IREFLECTIVEFOILSTICKERTARGET_H_
#define IREFLECTIVEFOILSTICKERTARGET_H_

#include "IPrismWithSizeTarget.h"

namespace SSI
{
	/**
	* Represents a reflective foil sticker.
	* <seealso cref="ISsiTargets"/>
	*/
	class IReflectiveFoilStickerTarget : public IPrismWithSizeTarget
	{
	public:
		virtual ~IReflectiveFoilStickerTarget();
	};
}
#endif