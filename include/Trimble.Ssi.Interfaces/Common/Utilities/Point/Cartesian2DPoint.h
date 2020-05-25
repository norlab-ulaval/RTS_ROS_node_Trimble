#ifndef CARTESIAN2DPOINT_H
#define CARTESIAN2DPOINT_H
#include "I2DPoint.h"

namespace SSI
{
	/**
	 * A 2D point in Cartesian space
	 */
	class Cartesian2DPoint : public I2DPoint
	{
	public:
		

		/**
		* Constructor.
		* @param x The x coordinate.
		* @param y The y coordinate.
		*/
		Cartesian2DPoint(double x, double y);

		/**
		* Constructor copy.
		* @param coordinates The Cartesian coordinates.
		*/
		Cartesian2DPoint(Cartesian2DPoint& coordinates);

		virtual ~Cartesian2DPoint();

		/**
		* Gets or sets the x coordinate.
		* @return
		* The x coordinate.
		*
		*/
		double getX();
		void setX(double xV);

		/**
		* Gets or sets the y coordinate.
		* @return
		* The y coordinate.
		*
		*/
		double getY();
		void setY(double yV);

	private:
		double _x;
		double _y;
	};
	
}
#endif // CARTESIAN2DPOINT_H
