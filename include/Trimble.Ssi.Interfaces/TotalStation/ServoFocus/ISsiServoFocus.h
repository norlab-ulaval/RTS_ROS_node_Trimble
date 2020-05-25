#ifndef ISSISERVOFOCUS_H_
#define ISSISERVOFOCUS_H_

#include "ISsiInterface.h"

namespace SSI
{
	/**
	* Provides members to access the servo focus functions of an instrument.
	* For a brief description of features and usage of various ISsiInterface see [Guides: Interfaces](@ref Guides_Interfaces)
	*/

	class ISsiServoFocus : public ISsiInterface
	{
	public:
		~ISsiServoFocus(void);

		/**
		* Sets the focus distance.
		* @param slopeDistance servo focus distance parameter.
		*/
		virtual void SetFocusDistance(double slopeDistance) = 0;
	};
}
#endif