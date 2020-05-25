#ifndef ITRUNNIONAXISERROR_H_
#define ITRUNNIONAXISERROR_H_

#include "IInstrumentError.h"

namespace SSI
{
	/**
	* Defines members to access correction values for Trunnion Axis errors.
	* <seealso cref="ISsiCorrectionValues"/>
	*/
	class ITrunnionAxisError : public IInstrumentError
	{
	public:
		virtual ~ITrunnionAxisError(void);

		/**
		* Gets the trunnion Angle value.
		* @return Radian value representing the angle.
		*/
		virtual double getAngle() const = 0;
	};
}
#endif