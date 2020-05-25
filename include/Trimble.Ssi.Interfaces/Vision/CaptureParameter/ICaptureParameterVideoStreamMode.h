#ifndef ICAPTUREPARAMETERVIDEOSTREAMMODE_H_
#define ICAPTUREPARAMETERVIDEOSTREAMMODE_H_

#include "IVideoCaptureParameter.h"
#include "../Video/VideoStreamMode.h"
#include <vector>

namespace SSI
{
	/**
	* Represents a capture parameter for set up the video stream type of the instrument.
	*/
	class ICaptureParameterVideoStreamMode : public IVideoCaptureParameter
	{
	public:
		virtual ~ICaptureParameterVideoStreamMode();
	
		/**
		* Lists the supported video stream modes.
		* @return the supported video stream modes.
		*/
		virtual std::vector<VideoStreamMode> listSupportedVideoStreamModes() const = 0;

		/**
		* Determines whether the specified video stream mode is supported.
		* @param videoStreamMode The video stream mode.
		* @return true if supported; otherwise false
		*/
		virtual bool isSupported(VideoStreamMode videoStreamMode) const = 0;

		/**
		* Gets the video stream mode.
		* @return the video stream mode
		*/
		virtual VideoStreamMode getVideoStreamMode() const = 0;

		/**
		* Sets the video stream mode.
		* @param the video stream mode
		*/
		virtual void setVideoStreamMode(VideoStreamMode videoStreamMode) = 0;
	};
}
#endif