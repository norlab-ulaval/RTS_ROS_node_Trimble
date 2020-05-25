#ifndef CARTESIAN3DPOINT_H
#define CARTESIAN3DPOINT_H
#include "I3DPoint.h"
#include "Cartesian2DPoint.h"

namespace SSI
{
	/**
	 * A 3D point in Cartesian space
	 */
	class Cartesian3DPoint : public Cartesian2DPoint, public I3DPoint
	{
	public:

		/**
		* Constructor.
		* @param x The x coordinate.
		* @param y The y coordinate.
		* @param z The z coordinate.
		*/
		Cartesian3DPoint(double x, double y, double z);

		/**
		* Constructor copy.
		* @param coordinates The Cartesian coordinates.
		*/
		Cartesian3DPoint(Cartesian3DPoint& coordinates);

		virtual ~Cartesian3DPoint();

		/**
		* Gets the z coordinate.
		* @return
		* The z coordinate.
		*
		*/
		double getZ();


		/**
		* Sets the z coordinate.
		* @param z
		* The z coordinate.
		*
		*/
		void setZ(double z);

	private:
		double _z;
	};
}

#endif // CARTESIAN3DPOINT_H
