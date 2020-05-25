#ifndef ITRACKERCOLLIMATIONERROR_H_
#define ITRACKERCOLLIMATIONERROR_H_

#include "ICollimationError.h"

namespace SSI
{
	/**
	* Defines members to access correction values for Tracker collimation errors.
	* <seealso cref="ISsiCorrectionValues"/>
	*/
	class ITrackerCollimationError : public ICollimationError
	{
	public:
		virtual ~ITrackerCollimationError(void);
	};
}
#endif