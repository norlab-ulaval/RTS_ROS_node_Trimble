#ifndef ONEBYTELUMINANCE_H
#define ONEBYTELUMINANCE_H
#include "IOneByteLuminance.h"

namespace SSI
{
	/**
	 * A 1-byte coded luminance
	 */
	class OneByteLuminance : public IOneByteLuminance
	{
	public:
		/**  Constructor.
		* @param luminance The luminance
		*/
		OneByteLuminance(unsigned char luminance);
		virtual ~OneByteLuminance();

		/**  Gets the value.
		* @return  The value.
		*/
		unsigned char getLuminance ();

		/**  Sets the value.
		* @return  The value.
		*/
		void setLuminance (unsigned char luminance );

	private:
		unsigned char _luminance;
	};
}

#endif // ONEBYTELUMINANCE_H
