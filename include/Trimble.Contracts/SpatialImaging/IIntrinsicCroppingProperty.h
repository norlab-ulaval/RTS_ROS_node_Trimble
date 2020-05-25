#ifndef TRIMBLE_CONTRACTS_IINTRINSICCROPPINGPROPERTY_H
#define TRIMBLE_CONTRACTS_IINTRINSICCROPPINGPROPERTY_H

#include "ISpatialImageProperty.h"

namespace Trimble_Contracts
{
    /// <summary>
    /// This class specifies the intrinsic cropping properties
    /// in the case the image is a sub or/and a scaled part of the detector.
    /// This handles also the case where the image is down sampled, or a 
    /// combination of cropping and down sampling.
    /// </summary>
    class IIntrinsicCroppingProperty : public ISpatialImageProperty
    {
    public:
        virtual ~IIntrinsicCroppingProperty();

		/// <summary>
        /// Gets the image width in pixel.
        /// Default value is WidthInPixel of <see cref="IntrinsicImageProperty"/>.
        /// </summary>
		virtual int getImageWidthInPixel() const = 0;

		/// <summary>
        /// Gets the image height in pixel.
        /// Default value is HeightInPixel of <see cref="IntrinsicImageProperty"/>.
        /// </summary>
        virtual int getImageHeightInPixel() const = 0;

        /// <summary>
        /// Gets the crop origin column in detector pixel relative to the detector upper left corner.
        /// Default value is 0.
        /// </summary>
        virtual int getSourceColumnInPixel() const = 0;

        /// <summary>
        /// Gets the crop origin row in detector pixel relative to the detector upper left corner.
        /// Default value is 0.
        /// </summary>
        virtual int getSourceRowInPixel() const = 0;

        /// <summary>
        /// Gets the crop width in detector pixel.
        /// Default value is WidthInPixel of <see cref="IntrinsicImageProperty"/>.
        /// </summary>
        virtual int getSourceWidthInPixel() const = 0;

        /// <summary>
        /// Gets the crop height in detector pixel.
        /// Default value is HeightInPixel of <see cref="IntrinsicImageProperty"/>.
        /// </summary>
        virtual int getSourceHeightInPixel() const = 0;
    };
}
#endif
