#ifndef POINT_H_
#define POINT_H_

namespace SSI
{
	/**
	* Point class containing information about X and Y.
	*/
	class Point
	{
	public:
		/**
		* Initializes a new instance of the Point class
		*/
		Point();
		/**
		* Initializes a new instance of the Point class with defined X and Y.
		* @param X and Y values for the point
		*/
		Point(int x, int y);

		int X;
		int Y;
	};
}
#endif