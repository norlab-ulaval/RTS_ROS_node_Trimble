#ifndef CORDINATES_H_
#define CORDINATES_H_

namespace SSI
{
	/*
	* Represents coordinates in the WGS84 reference system.
	*/
	class Coordinates
	{
	public:
		/*
		* Initializes a new instance of the Coordinates
		* @param double latitude
		* @param double longitude
		* @param double height
		*/
		Coordinates( double latitude, double longitude,double height) ;

		/*
		* Initializes a new instance of the Coordinates
		* @param Coordinates&
		*/
		Coordinates(const Coordinates& assignMe);

		/*
		* Gets the longitude.
		* @return double
		*/
		double getLongitude() const;

		/*
		* Gets the latitude.
		* @return double
		*/
		double getLatitude() const;

		/*
		* Gets the Height.
		* @return double
		*/
		double getHeight() const;

		Coordinates& operator =(const Coordinates &assignMe);

	private:
		double _longitude, _latitude, _height;
	};
}
#endif