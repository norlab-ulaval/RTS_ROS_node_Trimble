#ifndef CARTESIAN3DPOINTLUMINANCERGB_H
#define CARTESIAN3DPOINTLUMINANCERGB_H
#include "Cartesian3DPointAndLuminance.h"
#include "Utilities/Color/RGBColorModel.h"

namespace SSI
{
	class Cartesian3DPointLuminanceRgb :public Cartesian3DPointAndLuminance, public RGBColorModel
	{
	public:
		Cartesian3DPointLuminanceRgb(double x, double y, double z, unsigned char luminance, unsigned char red, unsigned char green, unsigned char blue);
		Cartesian3DPointLuminanceRgb(double x, double y, double z, unsigned char luminance, IRGBColorModel& rgbColorModel);
		~Cartesian3DPointLuminanceRgb();
	};
}

#endif // CARTESIAN3DPOINTLUMINANCERGB_H
