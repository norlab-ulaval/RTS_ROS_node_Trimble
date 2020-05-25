#ifndef IDISPLAYELEMENT_H_
#define IDISPLAYELEMENT_H_

#include "DisplayElementType.h"
#include "Rectangle.h"

namespace SSI
{
	/**
	* Represents an element which can be drawn on the display
	* ISsiDisplayBeta.createDisplayElement to create a specific display element on the DisplayElementType
	* @see ISsiDisplayBeta
	*/
	class IDisplayElement
	{
	public:
		virtual ~IDisplayElement();

		/**
		* Gets the bounds of the drawable area.
		* @return Rectangle representing the drawable area.
		*/
		virtual Rectangle getBounds() = 0;

		/**
		* Gets the display element type.
		* @return DisplayElementType value representing the type.
		*/
		virtual DisplayElementType getDisplayElementType() = 0;
	};
}
#endif

