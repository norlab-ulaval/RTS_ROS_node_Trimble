#ifndef ICOLLIMATIONERROR_H_
#define ICOLLIMATIONERROR_H_

#include "IInstrumentError.h"

namespace SSI
{
	/**
	* Defines members to access correction values for general collimation errors.
	* <seealso cref="ISsiCorrectionValues"/>
	*/
	class ICollimationError : public IInstrumentError
	{
	public:
		virtual ~ICollimationError();

		/**
		* Gets the horizontal angle in radian.
		* @return Radian value representing the horizontal angle.
		*/
		virtual double getHorizontalAngle() const = 0;

		/**
		* Gets the vertical angle in radian.
		* @return Radian value representing the vertical angle.
		*/
		virtual double getVerticalAngle() const = 0;
	};
}
#endif