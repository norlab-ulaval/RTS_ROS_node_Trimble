#ifndef IDISPLAYELEMENTBITMAP_H_
#define IDISPLAYELEMENTBITMAP_H_

#include "IDisplayElement.h"
#include "Point.h"

namespace SSI
{
	/**
	* Represents an element which can be drawn on the display
	* ISsiDisplayBeta.createDisplayElement to create a specific display element on the DisplayElementType
	* @see ISsiDisplayBeta
	*/
	class IDisplayElementBitmap : public IDisplayElement
	{
	public:
		virtual ~IDisplayElementBitmap();

		/**
		* Gets the maximum bitmap width.
		* @return int representing the maximum bitmap width.
		*/
		virtual int getMaxBitmapWidth() = 0;

		/**
		* Gets the maximum bitmap height.
		* @return int representing the maximum bitmap height.
		*/
		virtual int getMaxBitmapHeight() = 0;

		/**
		* Gets the stream length.
		* @return The stream length.
		*/
		virtual int getStreamLength() const = 0;

		/**
		* Gets the bitmap data.
		* @param streambuffer The buffer of the bitmap
		* @param length streambuffer length.
		* @return The bitmap data length.
		*/
		virtual int getStream(unsigned char* streambuffer, int length) const = 0;

		/**
		* Sets the bitmap data.
		* @param streambuffer The buffer of the bitmap.
		* @param length streambuffer length.
		*/
		virtual void setStream(unsigned char* streambuffer, int length) = 0;

		/**
		* Gets the start point.
		* @return Point representing the starting point.
		*/
		virtual Point getStartPoint() = 0;

		/**
		* Sets the start point.
		* @param point to be set as starting point.
		*/
		virtual void setStartPoint(Point point) = 0;
	};
}
#endif