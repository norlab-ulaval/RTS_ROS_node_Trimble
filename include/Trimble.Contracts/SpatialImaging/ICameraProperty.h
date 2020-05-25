#ifndef TRIMBLE_CONTRACTS_ICAMERAPROPERTY_H
#define TRIMBLE_CONTRACTS_ICAMERAPROPERTY_H

#include "ISpatialImageProperty.h"

namespace Trimble_Contracts
{
    /// <summary>
    /// Access to camera property.
    /// </summary>
    class ICameraProperty : public ISpatialImageProperty
    {
    public:
        virtual ~ICameraProperty();
        /// <summary>
        /// Gets the size of the pixel assuming pixels are square.
        /// </summary>
        /// <value>The size of the pixel.</value>
        virtual double getPixelSize() const = 0;
    };
}
#endif
