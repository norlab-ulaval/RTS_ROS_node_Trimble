#ifndef VIDEOSTREAMINGUPDATEEVENT_H_
#define VIDEOSTREAMINGUPDATEEVENT_H_

#include "Image/IImageCapture.h"

namespace SSI
{
	/**
	* An instance of this type is provided when a new video stream is provided.
	*/
	class VideoStreamingUpdateEvent
	{
	public:
		/**
		* Initializes a new instance of the VideoStreamingUpdateEvent class.
		* @param imageCapture A video image capture.
		*/
		VideoStreamingUpdateEvent(IImageCapture& imageCapture);
		virtual ~VideoStreamingUpdateEvent();

		/**
		* Gets the video stream.
		* @return The video stream or null if an error occurred.
		*/
		const IImageCapture& getImageCapture() const;
	private:
		VideoStreamingUpdateEvent();
		VideoStreamingUpdateEvent(const VideoStreamingUpdateEvent& copyMe);
		VideoStreamingUpdateEvent& operator=(const VideoStreamingUpdateEvent&);
		IImageCapture& _imageCapture;
	};
}
#endif