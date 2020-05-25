#ifndef RGBCOLORMODEL_H
#define RGBCOLORMODEL_H
#include "IRGBColorModel.h"

namespace SSI
{
	/**
	 *  Color using the RGB model
	 */
	class RGBColorModel :public IRGBColorModel
	{
	public:

		virtual ~RGBColorModel();

		/**
		* Constructor.
		* @param red The red.
		* @param green The green.
		* @param blue The blue.
		*/
		RGBColorModel(unsigned char red, unsigned char green, unsigned char blue);

		/**
		* Gets the red.
		* @return
		* The red.
		*
		*/
		unsigned char getRed();

		/**
		* Sets the red.
		* @param red The red.
		*
		*/
		void setRed(unsigned char red);

		/**
		* Gets the green.
		* @return
		* The green.
		*
		*/
		unsigned char getGreen();

		/**
		* Sets the green.
		* @param green  The green.
		*
		*/
		void setGreen(unsigned char green);

		/**
		* Gets the blue.
		* @return
		* The blue.
		*
		*/
		unsigned char getBlue();
		/**
		* Sets the blue.
		* @param blue The blue.
		*
		*/
		void setBlue(unsigned char blue);

	private:
		char _red;
		char _green;
		char _blue;
	};
	
}
#endif // RGBCOLORMODEL_H
