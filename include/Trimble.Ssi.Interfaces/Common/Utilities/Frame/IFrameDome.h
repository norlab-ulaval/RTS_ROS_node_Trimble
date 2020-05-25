#ifndef IFRAMEDOME_H
#define IFRAMEDOME_H
#include "IFrame.h"
#include "IFrameVerticalLimits.h"
#include "IFrameBounds.h"

namespace SSI
{
	/**
	*  Any dome that includes a Pole (north or south). Such a frame define a circle centered on a
	*  pole of the sphere surrounding the instrument. It is a particular case of a ring frame where
	*  the start value is automatically set to allowed minimal value.
	* @see Trimble.Ssi.Interfaces.Utilities.Frame.IFrame
	* @see Trimble.Ssi.Interfaces.Utilities.Frame.IFrameVerticalLimits
	* @see Trimble.Ssi.Interfaces.Utilities.Frame.IFrameBounds
	*/
	class IFrameDome : public virtual IFrame, public virtual IFrameVerticalLimits, public virtual IFrameBounds
	{
	public:
		virtual ~IFrameDome();


		/**
		* Gets the vertical angle. Angle is adjusted according to allowed limits.
		* @return
		* The vertical angle in radian. Z axis reference.
		*/
		virtual double getVerticalAngle() = 0;


		/**
		* Sets the vertical angle. Angle is adjusted according to allowed limits.
		*/
		virtual void setVerticalAngle(double vertricalAngle) = 0;
	};
}

#endif // IFRAMEDOME_H
