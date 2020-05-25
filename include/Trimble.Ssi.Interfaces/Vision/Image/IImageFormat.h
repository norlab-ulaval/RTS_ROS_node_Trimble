#ifndef IIMAGEFORMAT_H_
#define IIMAGEFORMAT_H_

#include "ImageFormatType.h"

namespace SSI
{
	/**
	* Represents the base of an image format
	*/
	class IImageFormat
	{
	public:
		virtual ~IImageFormat();
	
		/**
		* Gets the type of the format.
		* @return The type of the format.
		*/
		virtual ImageFormatType getFormatType() const = 0;

		virtual  IImageFormat * clone() =0;
	};
}
#endif