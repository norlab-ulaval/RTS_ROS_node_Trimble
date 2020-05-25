#ifndef ICAPTUREPARAMETERIMAGERESOLUTION_H_
#define ICAPTUREPARAMETERIMAGERESOLUTION_H_

#include "../Image/Resolution.h"
#include "IImageCaptureParameter.h"
#include "IPanoramicCaptureParameter.h"
#include <vector>

namespace SSI
{
	/**
	* Represents a capture parameter for defining the resolution of images.
	*/
	class ICaptureParameterImageResolution : public IImageCaptureParameter, public IPanoramicCaptureParameter
	{
	public:
		virtual ~ICaptureParameterImageResolution();

		/**
		* Lists the supported resolutions.
		* @return the possible resolutions
		*/
		virtual std::vector<Resolution> listSupportedResolutions() const = 0;

		/**
		* Determines whether the specified resolution is supported.
		* @param imageResolution The image resolution.
		* @return true if supported; otherwise false
		*/
		virtual bool isSupported(Resolution imageResolution) const = 0;

		/**
		* Gets the resolution.
		* @return The resolution.
		*/
		virtual Resolution getResolution() const = 0;
	
		/**
		* Sets the resolution.
		* @param The resolution.
		*/
		virtual void setResolution(Resolution resolution) = 0;
	};
}
#endif