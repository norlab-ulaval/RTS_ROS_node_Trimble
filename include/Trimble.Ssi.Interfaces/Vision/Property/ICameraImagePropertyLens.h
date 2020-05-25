#ifndef ICAMERAPROPERTYLENS_H_
#define ICAMERAPROPERTYLENS_H_

#include "IImagingProperty.h"
#include <string>

namespace SSI
{
	/**
	* Represents an image property carrying information about the cameras lens.
	*/
	class ICameraImagePropertyLens : public IImagingProperty
	{
	public:
		virtual ~ICameraImagePropertyLens();
	
		/**
		* Gets the lens model.
		* @return The lens model.
		*/
		virtual std::string getLensModel() const = 0;

		/**
		* Gets the identifier of the lens.
		* @return The identifier of the lens.
		*/
		virtual std::string lensId() const = 0;
	};
}
#endif