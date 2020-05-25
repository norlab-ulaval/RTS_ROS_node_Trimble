#ifndef IOPTICALCOLLIMATIONERROR_H_
#define IOPTICALCOLLIMATIONERROR_H_

#include "ICollimationError.h"

namespace SSI
{
	/**
	* Defines members to access correction values for Optical collimation errors.
	* <seealso cref="ISsiCorrectionValues"/>
	*/
	class IOpticalCollimationError : public ICollimationError
	{
	public:
		virtual ~IOpticalCollimationError(void);
	};
}
#endif