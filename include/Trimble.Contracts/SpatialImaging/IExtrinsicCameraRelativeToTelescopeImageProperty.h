#ifndef TRIMBLE_CONTRACTS_IEXTRINSICCAMERARELATIVETOTELESCOPEIMAGEPROPERTY_H
#define TRIMBLE_CONTRACTS_IEXTRINSICCAMERARELATIVETOTELESCOPEIMAGEPROPERTY_H

#include "ISpatialImageProperty.h"

namespace Trimble_Contracts
{
    /// <summary>
    /// This class specifies the extrinsic rotation and translation of the camera lens relative to the camera holder reference system.
    /// </summary>
    class IExtrinsicCameraRelativeToTelescopeImageProperty : public ISpatialImageProperty
    {
    public:
        virtual ~IExtrinsicCameraRelativeToTelescopeImageProperty();
        /// <summary>
        /// Gets or sets the camera position relative to camera holder center along X axis.
        /// Default value: 0.
        /// </summary>
        virtual double getCameraPositionX() const = 0;
        virtual void setCameraPositionX(double value) = 0;

        /// <summary>
        /// Gets or sets the camera position relative to camera holder center along Y axis.
        /// Default value: 0.
        /// </summary>
        virtual double getCameraPositionY() const = 0;
        virtual void setCameraPositionY(double value) = 0;

        /// <summary>
        /// Gets or sets the camera position relative to camera holder center along Z axis.
        /// Default value: 0.
        /// </summary>
        virtual double getCameraPositionZ() const = 0;
        virtual void setCameraPositionZ(double value) = 0;

        /// <summary>
        /// Gets or sets the X axis part of camera rotation arround camera holder.
        /// Default value: 0.
        /// </summary>
        virtual double getCameraRotationX() const = 0;
        virtual void setCameraRotationX(double value) = 0;

        /// <summary>
        /// Gets or sets the X axis part of camera rotation arround camera holder.
        /// Default value: 0.
        /// </summary>
        virtual double getCameraRotationY() const = 0;
        virtual void setCameraRotationY(double value) = 0;

        /// <summary>
        /// Gets or sets the Z axis part of camera rotation arround camera holder.
        /// Default value: 0.
        /// </summary>
        virtual double getCameraRotationZ() const = 0;
        virtual void setCameraRotationZ(double value) = 0;
    };
}
#endif
