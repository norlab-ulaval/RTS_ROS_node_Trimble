#ifndef IMAGEUPDATEEVENT_H_
#define IMAGEUPDATEEVENT_H_

#include "IImageCapture.h"

namespace SSI
{
	/**
	* An instance of this type is provided when an image has been captured or downloaded.
	*/
	class ImageUpdateEvent
	{
	public:
		/**
		* Initializes a new instance of the ImageUpdateEventArgs class.
		* @param image Result of the image capture.
		*/
		ImageUpdateEvent(IImageCapture& image);
		virtual ~ImageUpdateEvent();

		/**
		* Gets the image capture result.
		* @return The image resulting from a capture or a video.
		*/
		const IImageCapture& getImage() const;
	private:
		IImageCapture& _image;//< the image
	};
}
#endif