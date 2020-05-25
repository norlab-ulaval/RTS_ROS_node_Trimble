#ifndef IRGBCOLORMODEL_H
#define IRGBCOLORMODEL_H
#include "IColor.h"

namespace SSI
{
	/**
	 * Base interface for color using the RGB model
	 */
	class IRGBColorModel :public IColor
	{
	public:
		virtual ~IRGBColorModel();

		/**
		* Gets the red.
		* @return
		* The red.
		*
		*/
		virtual unsigned char getRed() = 0;

		/**
		* Sets the red.
		* @param red The red.
		*
		*/
		virtual void setRed(unsigned char red) = 0;

		/**
		* Gets the green.
		* @return
		* The green.
		*
		*/
		virtual unsigned char getGreen() = 0;

		/**
		* Sets the green.
		* @param green  The green.
		*
		*/
		virtual void setGreen(unsigned char green) = 0;

		/**
		* Gets the blue.
		* @return
		* The blue.
		*
		*/
		virtual unsigned char getBlue() = 0;
		/**
		* Sets the blue.
		* @param blue The blue.
		*
		*/
		virtual void setBlue(unsigned char blue) = 0;
	};
}

#endif // IRGBCOLORMODEL_H
