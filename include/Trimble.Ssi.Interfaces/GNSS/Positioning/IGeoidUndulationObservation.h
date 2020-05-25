#ifndef IGEOIDUNDULATIONOBSERVATION_H_
#define IGEOIDUNDULATIONOBSERVATION_H_

#include "IGNSSObservation.h"

namespace SSI
{
    class IGeoidUndulationObservation : public IGNSSObservation
    {
    public:
        virtual ~IGeoidUndulationObservation();

        virtual double getDeviation() = 0;
    };
}

#endif
