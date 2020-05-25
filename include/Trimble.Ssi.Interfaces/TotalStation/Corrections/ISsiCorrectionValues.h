#ifndef ISSICORRECTIONVALUES_H_
#define ISSICORRECTIONVALUES_H_

#include "ISsiInterface.h"
#include "IInstrumentError.h"
#include "CorrectionValueType.h"

namespace SSI
{
	/**
	* Provides members to access the correction values of an instrument.
	* For a brief description of features and usage of various <see cref="ISsiInterface"/> see [Guides: Interfaces](@ref Guides_Interfaces).
	*/
	class ISsiCorrectionValues : public ISsiInterface
	{
	public:
		virtual ~ISsiCorrectionValues();

		/**
		* Tries to get an <see cref="IInstrumentError"/> instance of type IInstrumentError.
		* @return An instance of the requested <see cref="IInstrumentError"/> if supported.
		*/
		virtual IInstrumentError* getError(CorrectionValueType correctionValueType) = 0;
	};
}
#endif