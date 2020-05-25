#ifndef ICAPTUREPARAMETER_H_
#define ICAPTUREPARAMETER_H_

#include "CaptureParameterType.h"

namespace SSI
{
	/**
	* Represents a basic capture parameter.
	*/
	class ICaptureParameter
	{
	public:
		virtual ~ICaptureParameter();
	
		/**
		* Gets the type.
		* @return the type
		*/
		virtual CaptureParameterType getType() const = 0;
	};
}
#endif