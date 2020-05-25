#ifndef POINTFORMATTYPE_H
#define POINTFORMATTYPE_H
namespace SSI
{
	/**
	* Represents a type of a point format.
	*/
	enum PointFormatType
	{
		/**
		* A format with Cartesian coordinates.
		*/
		PointFormat_CartesianCoordinates,

		/**
		* A format with Cartesian coordinates and luminance.
		*/
		PointFormat_CartesianCoordinatesAndLuminance,

		/**
		* A format with Cartesian coordinates and luminance and RGB.
		*/
		PointFormat_CartesianCoordinatesLuminanceRGB
	};
}
#endif // POINTFORMATTYPE_H
