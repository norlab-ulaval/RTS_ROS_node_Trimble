#ifndef ICAMERAFEATURE_H_
#define ICAMERAFEATURE_H_

#include "../CaptureParameter/ICaptureParameter.h"
#include "CameraFeatureType.h"

#include <vector>

namespace SSI
{
    /**
    * The base interface for a feature of a camera.
    */
    class ICameraFeature
    {
    public:
        virtual ~ICameraFeature();
        /**
        * Gets the type of the feature.
        * @return The type of the feature.
        */
        virtual CameraFeatureType getFeatureType() const = 0;

        /**
        * Lists the supported capture parameter types.
        * @return the supported capture parameter types.
        */
        virtual std::vector<CaptureParameterType> listSupportedCaptureParameterTypes() const = 0;

        /**
        * Determines whether the specified capture parameter type is supported.
        * @param captureParameterType Type of the capture parameter.
        * @return true if supported; otherwise false
        */
        virtual bool isSupported(CaptureParameterType captureParameterType) const = 0;

        /**
        * Creates the capture parameter.
        * @param type The type.
        * @return the capture parameter
        */
        virtual ICaptureParameter* createCaptureParameter(CaptureParameterType type) = 0;
    };
}
#endif
