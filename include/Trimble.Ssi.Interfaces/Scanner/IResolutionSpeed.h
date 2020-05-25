#ifndef IRESOLUTIONSPEED_H
#define IRESOLUTIONSPEED_H
#include "IScanResolution.h"
#include "SphericalAngles.h"

namespace SSI
{
    /**
    * Any resolution defined by vertical speed and frequency.
    * @see Trimble.Ssi.Interfaces.Scanner.IScanResolution
    */
    class IResolutionSpeed : public virtual IScanResolution
    {
    public:
        virtual ~IResolutionSpeed();

        /**
        * Gets the vertical speed. Vertical speed is adjusted according to
        * allowed min and max.
        * @return
        * The vertical speed in TR/s.
        *
        */
        virtual double getVerticalSpeed() = 0;

        /**
        * Sets the vertical speed. Vertical speed is adjusted according to
        * allowed min and max.
        * @param speed
        * The vertical speed in TR/s.
        *
        */
        virtual void setVerticalSpeed(double speed) = 0;

        /**
        * Gets the minimum vertical speed value.
        * @return
        * The vertical speed minimum.
        *
        */
        virtual double getVerticalSpeedMin() = 0;

        /**
        * Gets the maximum vertical speed value.
        * @return
        * The vertical speed maximum.
        *
        */
        virtual double getVerticalSpeedMax() = 0;

        /**
        * Gets the frequency. Frequency is adjusted according to
        * allowed min and max.
        * @return
        * The frequency in Hz.
        *
        */
        virtual double getFrequency() = 0;

        /**
        * Sets the frequency. Frequency is adjusted according to
        * allowed min and max.
        * @param frequency
        * The frequency in Hz.
        *
        */
        virtual void setFrequency(double frequency) = 0;

        /**
        * Gets the minimum frequency value.
        * @return
        * The frequency minimum.
        *
        */
        virtual double getFrequencyMin() = 0;

        /**
        * Gets the maximum frequency value.
        * @return
        * The frequency maximum.
        *
        */
        virtual double getFrequencyMax() = 0;
    };

}
#endif // IRESOLUTIONSPEED_H
