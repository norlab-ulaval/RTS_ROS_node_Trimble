#ifndef TRIMBLE_CONTRACTS_IEXTRINSICTELESCOPERELATIVETOINSTRUMENTIMAGEPROPERTY_H
#define TRIMBLE_CONTRACTS_IEXTRINSICTELESCOPERELATIVETOINSTRUMENTIMAGEPROPERTY_H

#include "ISpatialImageProperty.h"

namespace Trimble_Contracts
{
    /// <summary>
    /// This class specifies rotation and translation of the movable camera holder relative to instrument base reference system.
    /// </summary>
    class IExtrinsicTelescopeRelativeToInstrumentImageProperty : public ISpatialImageProperty
    {
    public:
        virtual ~IExtrinsicTelescopeRelativeToInstrumentImageProperty();
        /// <summary>
        /// Gets or sets the camera holder position relative to instrument center along X axis.
        /// </summary>
        virtual double getPositionX() const = 0;
        virtual void setPositionX(double value) = 0;

        /// <summary>
        /// Gets or sets the camera holder position relative to instrument center along Y axis.
        /// </summary>
        virtual double getPositionY() const = 0;
        virtual void setPositionY(double value) = 0;

        /// <summary>
        /// Gets or sets the camera holder position relative to instrument center along Z axis.
        /// </summary>
        virtual double getPositionZ() const = 0;
        virtual void setPositionZ(double value) = 0;

        /// <summary>
        /// Gets or sets X axis part of the camera holder rotation relative to the instrument base.
        /// </summary>
        virtual double getRotationX() const = 0;
        virtual void setRotationX(double value) = 0;

        /// <summary>
        /// Gets or sets Y axis part of the camera holder rotation relative to the instrument base.
        /// </summary>
        virtual double getRotationY() const = 0;
        virtual void setRotationY(double value) = 0;

        /// <summary>
        /// Gets or sets Z axis part of the camera holder rotation relative to the instrument base.
        /// </summary>
        virtual double getRotationZ() const = 0;
        virtual void setRotationZ(double value) = 0;
    };
}
#endif
