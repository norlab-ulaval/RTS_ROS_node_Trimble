#ifndef ISSIHORIZONTALANGLEADJUSTMENT_H_
#define ISSIHORIZONTALANGLEADJUSTMENT_H_

#include "ISsiInterface.h"

namespace SSI
{
	/**
	* Provides members to access the reference circle settings of an instrument.
	* For a brief description of features and usage of various <see cref="ISsiInterface"/> see [Guides: Interfaces](@ref Guides_Interfaces).
	*/
	class ISsiHorizontalAngleAdjustment : public ISsiInterface
	{
	public:
		virtual ~ISsiHorizontalAngleAdjustment();

		/**
		* Set Horizontal angle offset of the instrument.
		* @param horizontalAngleOffset horizontal angle offset value
		*/
		virtual void setHorizontalAngleOffset(double horizontalAngleOffset) = 0;

		/**
		* Get horizontal angle offset of the instrument.
		* @return The horizontal angle offset of the instrument
		*/
		virtual double getHorizontalAngleOffset() const = 0;
	};
}
#endif