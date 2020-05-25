#ifndef ICAPTUREPARAMETERPANORAMAFILEPATH_H
#define ICAPTUREPARAMETERPANORAMAFILEPATH_H
#include "IPanoramicCaptureParameter.h"
#include <string>

namespace SSI
{
    /**
    * Represents the parameter for specifying the file path of the panorama capture process
    * @see Trimble.Ssi.Interfaces.Vision.CaptureParameter.IPanoramicCaptureParameter
    */
    class ICaptureParameterPanoramaFilePath :public IPanoramicCaptureParameter
    {
    public:
        virtual ~ICaptureParameterPanoramaFilePath();

        /**
        * Gets the path to storethe panorama images.
        * @return
        * The path.
        */
        virtual std::string getFilePath() = 0;

        /**
        * Sets the path to storethe panorama images.
        */
        virtual void setFilePath(std::string filePath) = 0;
    };
}

#endif // ICAPTUREPARAMETERPANORAMAFILEPATH_H
