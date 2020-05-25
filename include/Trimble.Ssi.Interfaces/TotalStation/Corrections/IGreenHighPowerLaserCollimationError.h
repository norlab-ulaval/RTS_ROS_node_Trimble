#ifndef IGHPLCOLLIMATIONERROR_H_
#define IGHPLCOLLIMATIONERROR_H_

#include "ICollimationError.h"

namespace SSI
{
	/**
	* Defines members to access correction values for Green High Power Laser collimation errors.
	* <seealso cref="ISsiCorrectionValues"/>
	*/
	class IGreenHighPowerLaserCollimationError : public ICollimationError
	{
	public:
		virtual ~IGreenHighPowerLaserCollimationError(void);
	};
}
#endif