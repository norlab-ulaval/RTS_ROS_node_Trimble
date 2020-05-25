#ifndef IPOSITIONINGPARAMETERANTENNAHEIGHT_H_
#define IPOSITIONINGPARAMETERANTENNAHEIGHT_H_

#include "IPositioningParameter.h"

namespace SSI
{
    /*
    * Represents positioning antenna height parameter.
    */
    class IPositioningParameterAntennaHeight: public IPositioningParameter
    {
    public:
        virtual ~IPositioningParameterAntennaHeight();

        /*
        * Gets the height.
        * @return antenna height in meters
        */
        virtual double getAntennaHeight()=0;

        /*
        * Sets the height.
        * @param height
        */
        virtual void setAntennaHeight(double height)=0;

    };
}
#endif