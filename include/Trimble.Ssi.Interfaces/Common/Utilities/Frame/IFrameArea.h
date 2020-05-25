#ifndef IFRAMEAREA_H
#define IFRAMEAREA_H
#include "IFrameBounds.h"
#include "IFrame.h"
#include "IFrameVerticalLimits.h"

namespace SSI
{
    /**
    * Any frame that defines a Area frame area in term of angles without horizontal limits.
    * The horizontal range considered by the frame is the minimal one, except when InvertFrame is
    * set to true.
    * @see Trimble.Ssi.Interfaces.Utilities.Frame.IFrame
    * @see Trimble.Ssi.Interfaces.Utilities.Frame.IFrameVerticalLimits
    * @see Trimble.Ssi.Interfaces.Utilities.Frame.IFrameBounds
    */
    class IFrameArea : public virtual IFrame, public virtual IFrameVerticalLimits, public virtual IFrameBounds
    {
    public:
        virtual ~IFrameArea();


        /**
        * Gets the start horizontal angle.
        */
        virtual double getStartHorizontalAngle() = 0;


        /**
        * Gets the stop horizontal angle. 
        */
        virtual double getStopHorizontalAngle() = 0;

        /**
        * Sets the start horizontal angle.
        */
        virtual void setStartHorizontalAngle(double value) = 0;


        /**
        * Sets the stop horizontal angle.
        */
        virtual void setStopHorizontalAngle(double value) = 0;
    };
}

#endif // IFRAMERECTANGULAR_H
