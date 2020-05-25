#ifndef IIMAGECAPTURE_H_
#define IIMAGECAPTURE_H_

#include "ICapture.h"
#include "../Property/IImagingProperty.h"
#include "../Image/ImageFormatType.h"

namespace SSI
{
	/**
	* Interface for all types of captured images having a unique id.
	*/
	class IImageCapture : public ICapture
	{
	public:
		virtual ~IImageCapture();

		/**
		* Gets the stream length.
		* @return The stream length.
		*/
		virtual int getStreamLength() const = 0;

		/**
		* Gets the image data.
		* @param streambuffer The buffer of the target output image
		* @param length streambuffer length
		* @return The image data length.
		*/
		virtual int getStream(unsigned char* streambuffer, int length) const = 0;

		/**
		* Gets the width.
		* @return the width
		*/
		virtual unsigned int getWidth() const = 0;

		/**
		* Gets the height.
		* @return the height
		*/
		virtual unsigned int getHeight() const = 0;

		/**
		* Gets the format type of the stream.
		* @return The stream format type.
		*/
		virtual ImageFormatType getFormat() const = 0;

		/**
		* Gets the time stamp.
		* @return the timestamp
		*/
		virtual long long getTimeStamp() const = 0;

		/**
		* Determines whether the specified type has property.
		* @param type The type.
		* @return <c>true</c> if the specified type has property; otherwise, <c>false</c>.
		*/
		virtual bool hasProperty(ImagingPropertyType type) const = 0;

		/**
		* Gets the property.
		* @param type The type.
		* @return the image property
		*/
		virtual IImagingProperty* getProperty(ImagingPropertyType type) const = 0;
	};
}
#endif