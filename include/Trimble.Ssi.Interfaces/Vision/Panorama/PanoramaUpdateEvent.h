#ifndef PANORAMAUPDATEEVENT_H_
#define PANORAMAUPDATEEVENT_H_

#include "Image/ICapture.h"

namespace SSI
{
	/**
	* An instance of this type is provided for each image of a panorama being captured.
	* It provides the image raster data and information on its topology.
	*/
	class PanoramaUpdateEvent
	{
	public:
		/**
		* Initializes a new instance of the PanoramaUpdateEvent class.
		* @param capture The result of the image capture
		* @param index Index of the image
		*/
		PanoramaUpdateEvent(ICapture& capture, int index);
		virtual ~PanoramaUpdateEvent();

		/**
		* Gets the image index within the panorama. Can be used when redoing part of a panorama.
		* @return The image index.
		*/
		int getImageIndex() const;

		/**
		* Gets the capture.
		* @return the capture
		*/
		const ICapture& getCapture() const;
	private:
		PanoramaUpdateEvent();
		PanoramaUpdateEvent(const PanoramaUpdateEvent& copyMe);
		PanoramaUpdateEvent& operator=(const PanoramaUpdateEvent&);
		ICapture& _capture;
		int _imageIndex;
	};
}
#endif