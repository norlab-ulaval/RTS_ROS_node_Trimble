#ifndef ICAPTUREPARAMETERBRIGHTNESS_H_
#define ICAPTUREPARAMETERBRIGHTNESS_H_
#include "IGeneralCaptureParameter.h"

namespace SSI
{
	/**
	* Represents a capture parameter for defining the brightness modifier.
	*/
	class ICaptureParameterBrightness : public IGeneralCaptureParameter
	{
	public:
		virtual  ~ICaptureParameterBrightness();

		/**
		* Gets the min brightness.
		* @return the min brightness
		*/
		virtual int getMinBrightness() const = 0;

		/**
		* Gets the max brightness.
		* @return the max brightness
		*/
		virtual int getMaxBrightness() const = 0;

		/**
		* Gets the brightness.
		* @return The brightness.
		*/
		virtual int getBrightness() const = 0;
	
		/**
		* sets the brightness.
		* @param brightness The brightness.
		*/
		virtual void setBrightness(int brightness) = 0;
	};
}
#endif