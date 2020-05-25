#ifndef IDISPLAYELEMENTTEXT_H_
#define IDISPLAYELEMENTTEXT_H_

#include "IDisplayElement.h"
#include "Point.h"
#include <string>

namespace SSI
{
	/**
	* Represents an element which can be drawn on the display
	* ISsiDisplayBeta.createDisplayElement to create a specific display element on the DisplayElementType
	* @see ISsiDisplayBeta
	*/
	class IDisplayElementText : public IDisplayElement
	{
	public:
		virtual ~IDisplayElementText();
	
		/**
		* Gets the start point.
		* @return Point representing the starting point.
		*/
		virtual Point getStartPoint() = 0;

		/**
		* Sets the start point.
		* @param point to be set as starting point.
		*/
		virtual void setStartPoint(Point point) = 0;

		/**
		* Gets the text.
		* @return string representing the text.
		*/
		virtual std::string getText() = 0;

		/**
		* Sets the text.
		* @return string to be set as text.
		*/
		virtual void setText(std::string text) = 0;
	};
}
#endif