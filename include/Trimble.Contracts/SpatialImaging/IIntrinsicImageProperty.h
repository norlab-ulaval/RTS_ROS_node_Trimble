#ifndef TRIMBLE_CONTRACTS_IINTRINSICIMAGEPROPERTY_H
#define TRIMBLE_CONTRACTS_IINTRINSICIMAGEPROPERTY_H

#include "ISpatialImageProperty.h"

namespace Trimble_Contracts
{
    /// <summary>
    /// This class specifies the intrinsic image properties considering a free distortion image.
    /// It represents a combination of pure camera calibration constants and image related properties.
    /// </summary>
    /// <remarks>
    /// If the image has distortion, these intrinsic parameters are not sufficient and must be associated
    /// with <see cref="IntrinsicDistortionImageProperty"/>.
    /// Also these parameters are image resolution dependant.
    /// </remarks>
    class IIntrinsicImageProperty : public ISpatialImageProperty
    {
    public:
        virtual ~IIntrinsicImageProperty();
        /// <summary>
        /// Gets the width dimension (max column) of the image in pixels.
        /// </summary>
        virtual int getWidthInPixel() const = 0;

        /// <summary>
        /// Gets the height dimension (max row) of the image in pixels.
        /// </summary>
        virtual int getHeightInPixel() const = 0;

        /// <summary>
        /// Gets the principal distance in sub-pixels.
        /// It reflects the z axis coordinate of the image's origin relative to the camera lens,
        /// or the negative focal length in sub-pixels.
        /// </summary>
        virtual double getPrincipalDistanceInPixel() const = 0;

        /// <summary>
        /// Gets the principal point column in sub-pixels relative to the image upper left corner.
        /// Usually close to WidthInPixel / 2.
        /// </summary>
        /// <value>
        /// The principal point column in pixel.
        /// </value>
        virtual double getPrincipalPointColumnInPixel() const = 0;

        /// <summary>
        /// Gets the principal point row in sub-pixels relative to the image upper left corner.
        /// Usually close to HeightInPixel / 2.
        /// </summary>
        /// <value>
        /// The principal point row in pixel.
        /// </value>
        virtual double getPrincipalPointRowInPixel() const = 0;
    };
}
#endif
