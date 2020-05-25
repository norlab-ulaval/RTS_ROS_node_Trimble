#ifndef ICAMERAPROPERTYORIENTATION_H_
#define ICAMERAPROPERTYORIENTATION_H_

#include "IImagingProperty.h"
#include <string>

namespace SSI
{
	/**
	* Represents an image property carrying information about the cameras orientation.
	*/
	class ICameraImagePropertyOrientation : public IImagingProperty
	{
	public:
		virtual ~ICameraImagePropertyOrientation();
	
		/**
		* Gets the orientation.
		* @return The orientation.
		*/
		virtual std::string getOrientation() const = 0;
	};
}
#endif