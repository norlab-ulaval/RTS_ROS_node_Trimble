#ifndef ICAPTUREPARAMETERIMAGEFORMAT_H_
#define ICAPTUREPARAMETERIMAGEFORMAT_H_

#include "../Image/IImageFormat.h"
#include "IImageCaptureParameter.h"
#include "IPanoramicCaptureParameter.h"
#include <vector>

namespace SSI
{
	/**
	* Represents a capture parameter for defining the image Format of image captures and video updates.
	*/
	class ICaptureParameterImageFormat : public IImageCaptureParameter, public IPanoramicCaptureParameter
	{
	public:
		virtual ~ICaptureParameterImageFormat();

		/**
		* Lists the supported image format types.
		* @return the supported image format types
		*/
		virtual std::vector<ImageFormatType> listSupportedImageFormatTypes() const = 0;

		/**
		* Determines whether the specified image format type is supported.
		* @param imageFormatType Type of the image format.
		* @return true if supported; otherwise false
		*/
		virtual bool isSupported(ImageFormatType imageFormatType) const = 0;

		/**
		* Creates the image format.
		* @param imageFormatType the image format type
		* @return the image format
		*/
		virtual IImageFormat* createImageFormat(ImageFormatType imageFormatType) const = 0;

		/**
		* Gets the current image format.
		* @return the image format
		*/
		virtual IImageFormat* getImageFormat() const = 0;
	
		/**
		* Sets the current image format.
		* @param format the image format
		*/
		virtual void setImageFormat(IImageFormat* format)  = 0;

		/**
		* Gets default the image format.
		* @return The image format.
		*/
		virtual IImageFormat* getDefaultImageFormat() = 0;
	};
}
#endif