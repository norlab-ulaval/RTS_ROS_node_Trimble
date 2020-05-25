#ifndef IONEBYTELUMINANCE_H
#define IONEBYTELUMINANCE_H
#include "ILuminance.h"

namespace SSI
{
	/**
	 * Base interface for 1-byte coded luminance
	 */
	class IOneByteLuminance : public ILuminance
	{
	public:
		virtual ~IOneByteLuminance();

		/**
		* Gets the luminance.
		* @return
		* The luminance.
		*/
		virtual unsigned char getLuminance() = 0;
	};
}

#endif // IONEBYTELUMINANCE_H
