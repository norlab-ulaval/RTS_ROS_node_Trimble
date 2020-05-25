#ifndef ISSIINSTRUMENTACCURACIES_H_
#define ISSIINSTRUMENTACCURACIES_H_

#include "ISsiInterface.h"
#include <vector>
#include "IInstrumentAccuracy.h"

namespace SSI
{
	/**
	* Provides members to access accuracy values of an instrument.
	*/
	class ISsiInstrumentAccuracies: public ISsiInterface
	{
	public:
		virtual ~ISsiInstrumentAccuracies();

		/**
		* Tries to get an @see IInstrumentAccuracy instance
		* @return An instance of the requested @see IInstrumentAccuracy if supported; otherwise <c>null</c>.
		*/
		virtual IInstrumentAccuracy* getAccuracy() const = 0;
	};
}
#endif
