#ifndef SPHERICAL3DPOINT_H
#define SPHERICAL3DPOINT_H
#include "I3DPoint.h"

namespace SSI
{
	/**
	 * A 3D point in spherical space
	 */
	class Spherical3DPoint : public I3DPoint
	{
	public:
		/**
		* Constructor.
		* @param horizontalAngle The horizontal angle in radian. Y axis reference and clockwise.
		* @param verticalAngle The vertical angle in radian. Z axis reference.
		* @param slopeDistance The slope distance in meter.
		*/
		Spherical3DPoint(double horizontalAngle, double verticalAngle, double slopeDistance);

		virtual ~Spherical3DPoint();
		

		/**
		* Gets the horizontal angle.
		* @return
		* The horizontal angle in radian. Y axis reference and clockwise.
		*
		*/
		double getHorizontalAngle();

		/**
		* Sets the horizontal angle.
		* @param  horizontalAngle
		* The horizontal angle in radian. Y axis reference and clockwise.
		*
		*/
		void setHorizontalAngle(double horizontalAngle);

		/**
		* Gets the vertical angle.
		* @return
		* The vertical angle in radian. Z axis reference.
		*
		*/
		double getVerticalAngle();

		/**
		* Sets the vertical angle.
		* @param verticalAngle
		* The vertical angle in radian. Z axis reference.
		*
		*/
		void setVerticalAngle(double verticalAngle);

		/**
		* Gets the slope distance.
		* @return
		* The slope distance in meter.
		*
		*/
		double getSlopeDistance();

		/**
		* Sets the slope distance.
		* @param slopeDistance
		* The slope distance in meter.
		*
		*/
		void setSlopeDistance(double slopeDistance);

	private:
		double _horizontalAngle;
		double _verticalAngle;
		double _slopeDistance;

	};
}

#endif // SPHERICAL3DPOINT_H
