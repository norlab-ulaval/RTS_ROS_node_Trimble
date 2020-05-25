#ifndef CARTESIAN3DPOINTANDLUMINANCE_H
#define CARTESIAN3DPOINTANDLUMINANCE_H
#include "Utilities/Point/Cartesian3DPoint.h"
#include "Utilities/Color/OneByteLuminance.h"

namespace SSI
{
	class Cartesian3DPointAndLuminance :public Cartesian3DPoint, public OneByteLuminance
	{
	public:
		Cartesian3DPointAndLuminance(double x, double y, double z, unsigned char luminance);
		virtual ~Cartesian3DPointAndLuminance();
	};
}

#endif // CARTESIAN3DPOINTANDLUMINANCE_H
