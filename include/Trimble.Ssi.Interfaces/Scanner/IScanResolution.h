#ifndef ISCANRESOLUTION_H
#define ISCANRESOLUTION_H
#include "ResolutionType.h"

namespace SSI
{
	/**
	 * Interface for any kind of scan resolution.
	 */
	class IScanResolution
	{
	public:
		virtual ~IScanResolution();

		/**
		 * Gets the type of the scan resolution.
		 * @return The type of the scan resolution.
		 */
		virtual  ResolutionType getResolutionType() = 0;

		virtual IScanResolution* clone()=0;
	};
}

#endif // ISCANRESOLUTION_H
