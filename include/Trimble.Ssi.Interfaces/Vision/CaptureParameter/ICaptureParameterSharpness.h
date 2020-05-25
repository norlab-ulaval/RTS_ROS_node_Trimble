#ifndef ICAPTUREPARAMETERSHARPNESS_H_
#define ICAPTUREPARAMETERSHARPNESS_H_

#include "IGeneralCaptureParameter.h"

namespace SSI
{
	/**
	* Represents a capture parameter for defining the sharpness of a taken image.
	*/
	class ICaptureParameterSharpness : public IGeneralCaptureParameter
	{
	public:
		virtual ~ICaptureParameterSharpness();

		/**
		* Gets the max sharpness value.
		* @return the max sharpness value
		*/
		virtual int getMaxSharpnessValue() const = 0;

		/**
		* Gets the sharpness modifier.
		* Use Values between 0 and <see cref="MaxSharpnessValue"/>.
		* @return The sharpness modifier.
		*/
		virtual int getSharpnessModifier() const = 0;
	
		/**
		* Sets the sharpness modifier.
		* Use Values between 0 and <see cref="MaxSharpnessValue"/>.
		* @param sharpnessModifier The sharpness modifier.
		*/
		virtual void setSharpnessModifier(int sharpnessModifier) = 0;
	};
}
#endif