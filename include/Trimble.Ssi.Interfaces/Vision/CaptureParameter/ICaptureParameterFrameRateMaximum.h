#ifndef ICAPTUREPARAMETERFRAMERATEMAXIMUM_H_
#define ICAPTUREPARAMETERFRAMERATEMAXIMUM_H_

#include "IVideoCaptureParameter.h"
#include "../Video/FrameRate.h"
#include <vector>

namespace SSI
{
	/**
	* Represents a capture parameter for regulating the maximum frame rate of a stream of video image updates.
	*/
	class ICaptureParameterFrameRateMaximum : public IVideoCaptureParameter
	{
	public:
		virtual ~ICaptureParameterFrameRateMaximum();

		/**
		* Lists the supported frame rates.
		* @return the supported frame rates
		*/
		virtual std::vector<FrameRate> listSupportedFrameRates() const = 0;

		/**
		* Determines whether the specified frame rate is supported.
		* @param frameRate The frame rate.
		* @return true if supported; otherwise false
		*/
		virtual bool isSupported(FrameRate frameRate) const = 0;

		/**
		* Gets the maximum frame rate.
		* @return the maximum frame rate
		*/
		virtual FrameRate getFrameRateMaximum() const = 0;
	
		/**
		* Sets the maximum frame rate.
		* @param the maximum frame rate
		*/
		virtual void setFrameRateMaximum(FrameRate frameRate) = 0;
	};
}
#endif