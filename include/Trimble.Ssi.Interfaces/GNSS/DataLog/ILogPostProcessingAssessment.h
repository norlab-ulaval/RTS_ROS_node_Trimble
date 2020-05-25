#ifndef ILOGPOSTPROCESSINGASSESSMENT_H_
#define ILOGPOSTPROCESSINGASSESSMENT_H_

#include "ILogInfo.h"

namespace SSI
{
    /**
    * Interface for accessing post processing assessment info.
    */
    class ILogPostProcessingAssessment: public ILogInfo
    {
    public:
        virtual ~ILogPostProcessingAssessment();
    
        /**
        * Gets the current PPA precision value in meter 
        * @return The PPA precision value.
        */
        virtual double getCurrent() = 0;

        /**
        * Gets the code PPA precision value in meter 
        * @return The code PPA precision value.
        */
        virtual double getCode() = 0;

        /**
        * Gets the carrier PPA precision value in meter 
        * @return The carrier PPA precision value.
        */
        virtual double getCarrier() = 0;
    };
}
#endif