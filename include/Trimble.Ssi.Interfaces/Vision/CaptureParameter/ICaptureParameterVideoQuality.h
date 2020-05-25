#ifndef ICAPTUREPARAMETERVIDEOQUALITY_H_
#define ICAPTUREPARAMETERVIDEOQUALITY_H_

#include "ICaptureParameter.h"

namespace SSI
{
	/**
	* Represents a capture parameter for defining the quality of the video.
	*/
	class ICaptureParameterVideoQuality : public ICaptureParameter
	{
	public:
		virtual ~ICaptureParameterVideoQuality();

		/**
		* Gets the video quality.
		* @return the video quality
		*/
		virtual double getVideoQuality() const = 0;

		/**
		* Sets the video quality.
		* Use values between 0 and 1.
		* @param quality The quality.
		*/
		virtual void setVideoQuality(double quality) = 0;
	};
}
#endif