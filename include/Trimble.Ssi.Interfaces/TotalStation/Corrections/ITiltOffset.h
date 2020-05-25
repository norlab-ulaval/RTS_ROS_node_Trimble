#ifndef ITILTOFFSETERROR_H_
#define ITILTOFFSETERROR_H_

#include "IInstrumentError.h"

namespace SSI
{
	/**
	* Defines members to access correction values for Tilt Offset errors.
	* <seealso cref="ISsiCorrectionValues"/>
	*/
	class ITiltOffset : public IInstrumentError
	{
	public:
		virtual ~ITiltOffset(void);

		/**
		* Gets the trunnion offset value.
		* @return trunnion offset value.
		*/
		virtual double getTrunnion() const = 0;

		/**
		* Gets the Sighting offset value.
		* @return Sighting offset value.
		*/
		virtual double getSighting() const = 0;
	};
}
#endif