#ifndef ICAPTURE_H_
#define ICAPTURE_H_

#include "CaptureType.h"

namespace SSI
{
	/**
	* Represents a base of a capture.
	*/
	class ICapture
	{
	public:
		virtual ~ICapture();
	
		/**
		* Gets the type of the capture.
		* @return The type of the capture.
		*/
		virtual CaptureType getCaptureType() const = 0;

		/**
		* Clone the image.
		*/
		virtual ICapture * clone() = 0;
	};
}
#endif