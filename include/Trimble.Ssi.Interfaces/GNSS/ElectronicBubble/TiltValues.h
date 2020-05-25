#ifndef TILTVALUES_H
#define TILTVALUES_H

namespace SSI
{
	/**
	* Represents tilt values.
	*/
	class TiltValues
	{
	public:
		TiltValues();
		TiltValues(double x, double y);
		TiltValues(const TiltValues &src);
		TiltValues& operator=(const TiltValues& assignMe);
	
		/**
		* Gets the X.
		* @return The X.
		*/
		double getX();

		/**
		* Gets the Y.
		* @return The Y.
		*/
		double getY();
	private:
		double _x, _y;
	};
}
#endif