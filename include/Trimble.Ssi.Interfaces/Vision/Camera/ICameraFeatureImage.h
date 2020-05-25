#ifndef ICAMERAFEATUREIMAGE_H_
#define ICAMERAFEATUREIMAGE_H_

#include "ICameraFeature.h"
#include "CaptureParameter/ICaptureParameter.h"
#include "Connection/ICommunicator.h"
#include "Property/ImagePropertyContainer.h"

#include "Image/ICapture.h"

#include <vector>

namespace SSI
{
    /**
    * This <see cref="ICameraFeature"/> is availiable if the Camera is capable of capture images
    */
    class ICameraFeatureImage : public ICameraFeature
    {
    public:
        virtual ~ICameraFeatureImage();

        /**
        * Captures the image without any parameters. Defaults get taken.
        * @return Returns an <see cref="ICapture"/> which could be either an image or a guid to an image, stored on the sensor
        */
        virtual ICapture* captureImage() = 0;

        /**
        * Capture an image at the current camera position.
        * @param captureParameters The capture parameters.
        * @return Returns an <see cref="ICapture" /> which could be either an image or a guid to an image, stored on the sensor
        */
        virtual ICapture* captureImage(std::vector<ICaptureParameter*> captureParameters) = 0;
    };
}
#endif
