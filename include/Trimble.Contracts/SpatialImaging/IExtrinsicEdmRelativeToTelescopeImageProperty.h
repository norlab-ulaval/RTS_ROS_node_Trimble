#ifndef TRIMBLE_CONTRACTS_IEXTRINSICEDMRELATIVETOTELESCOPEIMAGEPROPERTY_H
#define TRIMBLE_CONTRACTS_IEXTRINSICEDMRELATIVETOTELESCOPEIMAGEPROPERTY_H

#include "ISpatialImageProperty.h"

namespace Trimble_Contracts
{
/**
 * This class specifies the extrinsic rotation and translation of the electronic distance meter relative to the edm holder reference system.
 */
class IExtrinsicEdmRelativeToTelescopeImageProperty: public ISpatialImageProperty
{
public:
    virtual ~IExtrinsicEdmRelativeToTelescopeImageProperty();
    /**
     * Gets the edm position relative to edm holder center along X axis.
     * Default value: 0.
     */
    virtual double getEdmPositionX() const = 0;

    /**
     * Sets the edm position relative to edm holder center along X axis.
     * Default value: 0.
     */
    virtual void setEdmPositionX(double value) = 0;

    /**
     * Gets the edm position relative to edm holder center along Y axis.
     * Default value: 0.
     */
    virtual double getEdmPositionY() const = 0;

    /**
     * Sets the edm position relative to edm holder center along Y axis.
     * Default value: 0.
     */
    virtual void setEdmPositionY(double value) = 0;

    /**
     * Gets the edm position relative to edm holder center along Z axis.
     * Default value: 0.
     */
    virtual double getEdmPositionZ() const = 0;

    /**
     * sets the edm position relative to edm holder center along Z axis.
     * Default value: 0.
     */
    virtual void setEdmPositionZ(double value) = 0;

    /**
     * Gets the X axis part of edm rotation arround edm holder.
     * Default value: 0.
     */
    virtual double getEdmRotationX() const = 0;

    /**
     * Sets the X axis part of edm rotation arround edm holder.
     * Default value: 0.
     */
    virtual void setEdmRotationX(double value) = 0;

    /**
     * Gets the Y axis part of edm rotation arround edm holder.
     * Default value: 0.
     */
    virtual double getEdmRotationY() const = 0;

    /**
     * sets the Y axis part of edm rotation arround edm holder.
     * Default value: 0.
     */
    virtual void setEdmRotationY(double value) = 0;

    /**
     * Gets the Z axis part of edm rotation arround edm holder.
     * Default value: 0.
     */
    virtual double getEdmRotationZ() const = 0;

    /**
     * Sets the Z axis part of edm rotation arround edm holder.
     * Default value: 0.
     */
    virtual void setEdmRotationZ(double value) = 0;
};
}
#endif
