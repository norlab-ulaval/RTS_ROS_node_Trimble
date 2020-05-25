#ifndef ICAPTUREPARAMETERVIDEORESOLUTION_H_
#define ICAPTUREPARAMETERVIDEORESOLUTION_H_

#include "IVideoCaptureParameter.h"
#include "../Image/Resolution.h"
#include <vector>

namespace SSI
{
	/**
	* Represents a capture parameter for the resolution of video updates.
	*/
	class ICaptureParameterVideoResolution : public IVideoCaptureParameter
	{
	public:
		virtual ~ICaptureParameterVideoResolution();
		
		/**
		* Lists the supported resolutions.
		* @return
		*/
		virtual std::vector<Resolution> listSupportedResolutions() const = 0;

		/**
		* Determines whether the specified video resolution is supported.
		* @param videoResolution The video resolution.
		* @return true if supported; otherwise false
		*/
		virtual bool isSupported(Resolution videoResolution) const = 0;

		/**
		* Gets the resolution.
		* @return The resolution.
		*/
		virtual Resolution getResolution() const = 0;
	
		/**
		* Gets the resolution.
		* @param resolution The resolution.
		*/
		virtual void setResolution(Resolution resolution) = 0;
	};
}
#endif