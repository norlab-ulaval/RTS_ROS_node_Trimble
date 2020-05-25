#ifndef IFRAMERECTANGULAR_H
#define IFRAMERECTANGULAR_H
#include "IFrameBounds.h"
#include "HaVaAngles.h"
#include "IFrame.h"
#include "IFrameVerticalLimits.h"

namespace SSI
{
	/**
	* Any frame that defines a rectangular frame area in term of angles without horizontal limits.
	* The horizontal range considered by the frame is the minimal one, except when InvertFrame is
	* set to true.
	* @see Trimble.Ssi.Interfaces.Utilities.Frame.IFrame
	* @see Trimble.Ssi.Interfaces.Utilities.Frame.IFrameVerticalLimits
	* @see Trimble.Ssi.Interfaces.Utilities.Frame.IFrameBounds
	*/
	class IFrameRectangular : public virtual IFrame, public virtual IFrameVerticalLimits, public virtual IFrameBounds
	{
	public:
		virtual ~IFrameRectangular();


		/**
		* Gets the upper left corner. The returned angles cannot be modified. The only is to
		* set UpperLeftCorner to a new set of angles.
		* @return
		* Angles of the upper left corner.
		*/
		virtual HaVaAngles& getUpperLeftCorner() = 0;


		/**
		* Gets the lower right corner. The returned angles cannot be modified. The only is to
		* set LowerRightCorner to a new set of angles.
		* @return
		* Angles of the lower right corner.
		*
		*/
		virtual HaVaAngles& getLowerRightCorner() = 0;


		/**
		* Sets the opposite corners of the rectangular frame.
		* @param upperLeft The upperleft corner.
		* @param lowerRight The lowerright corner.
		*/
		virtual void setOppositeCorners(HaVaAngles& upperLeft, HaVaAngles& lowerRight) = 0;
	};
}

#endif // IFRAMERECTANGULAR_H
