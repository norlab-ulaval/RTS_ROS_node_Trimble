#ifndef TRIMBLE_CONTRACTS_ISPATIALIMAGEPROPERTY_H
#define TRIMBLE_CONTRACTS_ISPATIALIMAGEPROPERTY_H

#include "SpatialImagePropertyType.h"

namespace Trimble_Contracts
{
    /// <summary>
    /// The base class of all SpatialImageProperty
    /// </summary>
    class ISpatialImageProperty
    {
    public:
        virtual ~ISpatialImageProperty();
        /// <summary>
        /// Get SpatialImageProperty type
        /// </summary>
        /// <returns>The SpatialImageProperty type.</returns>
        virtual SpatialImagePropertyType getType() const = 0;
    };
}
#endif
