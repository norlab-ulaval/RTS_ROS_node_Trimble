#ifndef IIMAGEFORMATJPEG_H_
#define IIMAGEFORMATJPEG_H_

#include "IImageFormat.h"

namespace SSI
{
	/**
	* Represents an jpeg image format
	*/
	class IImageFormatJpeg : public IImageFormat
	{
	public:
		virtual ~IImageFormatJpeg();

		/**
		* Gets the quality between 0 and 1.
		* @return The quality between 0 and 1.
		*/
		virtual double getQuality() const = 0;
	
		/**
		* Sets the quality between 0 and 1.
		* @param quality The quality between 0 and 1.
		*/
		virtual void setQuality(double quality) = 0;
	};
}
#endif