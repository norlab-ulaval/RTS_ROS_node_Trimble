#ifndef SATELLITETYPE_H_
#define SATELLITETYPE_H_

namespace SSI
{
	/**
	* Represents Satellite type of @see ISatellite
	* @remark The value of @see ISatellite::getSatelliteType()
	* @see ISatellite
	* @see ISsiSatellites
	*/
	enum SatelliteType
	{
		/**
		* Satellite type is GPS.
		*/
		GPS,

		/**
		* Satellite type is SBAS.
		*/
		SBAS,

		/**
		* Satellite type is GLONASS.
		*/
		GLONASS,

		/**
		* Satellite type is OMNISTAR.
		*/
		OMNISTAR,

		/**
		* Satellite type is GALILEO.
		*/
		GALILEO,

		/**
		* Satellite type is BEIDOU.
		*/
		BEIDOU,

		/**
		* Satellite type is QZSS.
		*/
		QZSS
	};
}
#endif