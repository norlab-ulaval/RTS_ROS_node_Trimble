#ifndef IFRAMERING_H
#define IFRAMERING_H
#include "IFrame.h"
#include "IFrameVerticalLimits.h"
#include "IFrameBounds.h"

namespace SSI
{
	/**
	* Any ring frame that defines a 360° band around the instrument. It is always considered as
	* horizontal regarding the instrument Z axis.
	* @see Trimble.Ssi.Interfaces.Utilities.Frame.IFrame
	* @see Trimble.Ssi.Interfaces.Utilities.Frame.IFrameVerticalLimits
    * @see Trimble.Ssi.Interfaces.Utilities.Frame.IFrameBounds
    */
	class IFrameRing : public virtual IFrame, public virtual IFrameVerticalLimits, public virtual IFrameBounds
	{
	public:
		virtual ~IFrameRing();


		/**
		* Gets the start vertical angle. Angle is adjusted according to allowed limits.
		* @return
		* First vertical angle in radian. Z axis reference.
		*/
		virtual double getStartVerticalAngle() = 0;


		/**
		* Gets the start vertical angle. Angle is adjusted according to allowed limits.
		*/
		virtual void setStartVerticalAngle(double startVerticalAngle) = 0;

        /**
        * Gets the stop vertical angle. Angle is adjusted according to allowed limits.
        * @return
        * Second vertical angle in radian. Z axis reference.
        */
        virtual double getStopVerticalAngle() = 0;


        /**
        * Gets the stop vertical angle. Angle is adjusted according to allowed limits.
        */
        virtual void setStopVerticalAngle(double stopVerticalAngle) = 0;

	};
}

#endif // IFRAMERING_H
