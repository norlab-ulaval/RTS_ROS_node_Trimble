#ifndef TRIMBLE_CONTRACTS_IINTRINSICDISTORTIONIMAGEPROPERTY_H
#define TRIMBLE_CONTRACTS_IINTRINSICDISTORTIONIMAGEPROPERTY_H

#include "ISpatialImageProperty.h"
#include "LensType.h"

namespace Trimble_Contracts
{
    /// <summary>
    /// This class specifies a combination of a symmetric (or radial) and asymmetric distortion coefficients.
    /// </summary>

    /// <summary>
    /// Class to represent the optical lens of a camera including the various distortions that are possible.
    /// </summary>


    class IIntrinsicDistortionImageProperty : public ISpatialImageProperty
    {
    public:
        virtual ~IIntrinsicDistortionImageProperty();

        /// <summary>
        /// Gets or sets the lens type.
        /// </summary>
        /// <remarks>
        /// The lens type has an impact on how distortion are taken into account in computations.
        /// </remarks>
        /// <value>The lens type.</value>
        virtual LensType getLens() const = 0;
        virtual void setLens(LensType value) = 0;

        /// <summary>
        /// Gets or sets the ideal angular magnification.
        /// Default value: 1. Greater than 1 for magnification. Less than 1 for attenuation.
        /// </summary>
        virtual double getAngularMagnification() const = 0;
        virtual void setAngularMagnification(double value) = 0;

        /// <summary>
        /// Gets or sets the polynomial coefficient of for 2nd order approximation of symmetric distortion.
        /// Default value: 0.
        /// </summary>
        virtual double getSymmetric2() const = 0;
        virtual void setSymmetric2(double value) = 0;

        /// <summary>
        /// Gets or sets the polynomial coefficient of for 4th order approximation of symmetric distortion.
        /// Default value: 0.
        /// </summary>
        virtual double getSymmetric4() const = 0;
        virtual void setSymmetric4(double value) = 0;

        /// <summary>
        /// Gets or sets the polynomial coefficient of for 6th order approximation of symmetric distortion.
        /// Default value: 0.
        /// </summary>
        virtual double getSymmetric6() const = 0;
        virtual void setSymmetric6(double value) = 0;

        /// <summary>
        /// Gets or sets the polynomial coefficient of for 8th order approximation of symmetric distortion.
        /// Default value: 0.
        /// </summary>
        virtual double getSymmetric8() const = 0;
        virtual void setSymmetric8(double value) = 0;

        /// <summary>
        /// Gets or sets the row coordinate of asymmetric distortion.
        /// Default value: 0.
        /// </summary>
        virtual double getAsymmetricRow() const = 0;
        virtual void setAsymmetricRow(double value) = 0;

        /// <summary>
        /// Gets or sets the column coordinate of asymmetric distortion.
        /// Default value: 0.
        /// </summary>
        virtual double getAsymmetricCol() const = 0;
        virtual void setAsymmetricCol(double value) = 0;
    };
}
#endif
