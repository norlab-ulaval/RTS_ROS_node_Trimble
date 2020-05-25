#ifndef I3DPOINT_H
#define I3DPOINT_H
#include "I2DPoint.h"

namespace SSI
{
	/*
	 * Interface for any kind of 3D Point
	 */
	class I3DPoint : public I2DPoint
	{
	public:
		virtual ~I3DPoint();
	};
}

#endif // I3DPOINT_H
