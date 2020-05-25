#ifndef HAVAANGLES_H
#define HAVAANGLES_H

#define M_PI	    		(3.14159265358979323846)
#define INVALID_RADIAN	    1e37
#define EPSILON             4.94065645841247E-324

namespace SSI
{
	/**
	* Represents angles defined by a horizontal and a vertical radian angle.
	*/
	class HaVaAngles
	{
	public:
		HaVaAngles();
		HaVaAngles(const HaVaAngles &haVaAngles);
		~HaVaAngles();
		/**
		* Initializes a new instance of the @see HaVaAngles struct.
		* @param horizontalAngle The horizontal angle in radian. Y axis reference and clockwise.
		* @param verticalAngle The vertical angle in radian. Z axis reference.
		* <remarks>
		* The angles are not normalized.
		* </remarks>
		*/
		HaVaAngles(double horizontalAngle, double verticalAngle);

		/**
		* Gets the horizontal angle in radian. Y axis reference and clockwise.
		* @return
		* The horizontal angle in radian. Y axis reference and clockwise.
		*
		*/
		double getHorizontalAngle();

		void setHorizontalAngle(double horizontalAngle);

		/**
		* Gets the vertical angle in radian. Z axis reference.
		* @return
		* The vertical angle in radian. Z axis reference.
		*
		*/
		double getVerticalAngle();

		void setVerticalAngle(double verticalAngle);

		/**
		* Gets a value indicating whether this instance is empty.
		* @return
		*   true if this instance is empty; otherwise, <c>false</c>.
		*
		*/
		bool isEmpty();

		/**
		* Implements the operator ==.
		* @param a The first instance.
		* @param b The second instance.
		* <returns>
		* The result of the operator.
		* </returns>
		*/
		bool operator ==(HaVaAngles& b);

		/**
		* Implements the operator !=.
		* @param a The first instance.
		* @param b The second instance..
		* <returns>
		* The result of the operator.
		* </returns>
		*/
		bool operator !=(HaVaAngles& b);


		HaVaAngles& operator =(const HaVaAngles& b);

		/**
		* Implements the operator +.
		* @param a The first instance.
		* @param b The second instance..
		* <returns>
		* The result of the operator.
		* </returns>
		*/
		HaVaAngles& operator+(HaVaAngles& b);

		/**
		* Adds the specified angles to an instance of the @see HaVaAngles class.
		* <param name="angles">An instance of the @see HaVaAngles class.</param>
		* @param horizontalAngle The horizontal angle to add.
		* @param verticalAngle The vertical angle to add.
		* <returns>
		* A new instance of the @see HaVaAngles class.
		* </returns>
		* <remarks>
		* The <c>Add</c> adds the <paramref name="horizontalAngle" /> and <paramref name="verticalAngle" /> to the @see _horizontalAngle and @see _verticalAngle of the specified @see HaVaAngles.
		* </remarks>
		*/
		static HaVaAngles add(HaVaAngles angles, double horizontalAngle, double verticalAngle);

		static HaVaAngles add(HaVaAngles angles, HaVaAngles angles2);

		/**
		* Gets the normalized radian angle.
		* @param angle The angle to normalize in radian.
		* @returns The normalized angle in radian.
		*/
		static double getNormalizedRadianAngle(double angle);

		HaVaAngles* clone();

	private:
		double _horizontalAngle;
		double _verticalAngle;
	};
	
}
#endif // HAVAANGLES_H
