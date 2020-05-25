#ifndef SPHERICALANGLES_H_
#define SPHERICALANGLES_H_

namespace SSI
{
	/**
	* Represents spherical angles defined by a horizontal and a vertical radian angle.
	*/
	class SphericalAngles
	{
	public:
		/**
		* Adds the specified angles to the angles of the given class.
		* @param horizontalOffset horizontal angle in radian to add. Y axis reference and clockwise.
		* @param verticalOffset vertical angle in radian to add. Z axis reference.
		*/
		void add(double horizontalOffset, double verticalOffset);

		/**
		* destructor
		*/
		virtual ~SphericalAngles();

		/**
		* Creates an instance.
		* The provided angles will be normalized.
		* @param horizontalAngle The horizontal angle in radian. Y axis reference and clockwise.
		* @param verticalAngle The vertical angle in radian. Z axis reference.
		*/
		SphericalAngles(double horizontalAngle, double verticalAngle);

		/**
		* Gets the normalized horizontal angle in radian. Y axis reference and clockwise.
		* @return the normalized horizontal angle in radian. Y axis reference and clockwise.
		*/
		double getHorizontalAngle() const;

		/**
		* Gets the normalized vertical angle in radian. Z axis reference.
		* @return the normalized vertical angle in radian. Z axis reference.
		*/
		double getVerticalAngle() const;

		/**
		* Implementation of the == operator.
		* @param other the instance to compare with
		* @return <c>true</c> if equal; otherwise, <c>false</c>.
		*/
		bool operator==(SphericalAngles& other) const;

		/**
		* Implementation of the != operator.
		* @param other the instance to compare with
		* @return <c>true</c> if not equal; otherwise, <c>false</c>.
		*/
		bool operator!=(SphericalAngles& other) const;

		/**
		* Checks if the class holds valid angles.
		* @return true if valid false otherwise
		*/
		bool isValid() const;

		/**
		* set the class to not valid angles.
		*/
		void invalidate();

		/**
		* constructor
		*/
		SphericalAngles();

		/**
		* const copy constructor.
		* @param copyMe to copy
		*/
		SphericalAngles(const SphericalAngles& copyMe);

		/**
		* Implementation of assignment operator.
		* @param assignMe to assign from
		*/
		SphericalAngles& operator=(const SphericalAngles& assignMe);
	private:
		/**
		* Normalizes an angle in radian.
		* @param angle angle in radian to normalize
		* @return normalized angle in radian
		*/
		double getNormalizedRadianAngle(double angle);

		double _horizontalAngle; ///< horizontal angle in radian.
		double _verticalAngle; ///< vertical angle in radian.
	};
}
#endif