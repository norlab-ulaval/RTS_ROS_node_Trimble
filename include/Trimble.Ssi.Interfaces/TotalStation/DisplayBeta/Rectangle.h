#ifndef RECTANGLE_H_
#define RECTANGLE_H_

namespace SSI
{
	/**
	* Rectangle class containing information about X, Y, Width and Height.
	*/
	class Rectangle
	{
	public:
		/**
		* Initializes a new instance of the Point class
		*/
		Rectangle();
		/**
		* Initializes a new instance of the Point class with defined X and Y.
		* @param X and Y values for the point
		*/
		Rectangle(int x, int y, int width, int height);

		int X;
		int Y;
		int Width;
		int Height;
	};
}
#endif