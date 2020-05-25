#ifndef IISATELLITEMASKPARAMETERTYPE_H_
#define IISATELLITEMASKPARAMETERTYPE_H_

#include "SatelliteType.h"

namespace SSI
{
	/**
	* Represents correction link parameter.
	* @remark To get an enumeration of supported @see SatelliteMaskParameterType values, use @see ISsiSatellites::listSupportedSatelliteMaskParameterTypes.
	* @remark Use @see ISsiSatellites::createSatelliteMaskParameter to create an @see ISatelliteMaskParameter, which can be used to set the satellite masks of the GNSS Receiver
	* @see ISsiSatellites
	*/
	enum SatelliteMaskParameterType
	{
		/**
		* Satellite mask parameter type is min elevation.
		*/
		MinElevation,

		/**
		* Satellite mask parameter type is track GLONASS.
		*/
		TrackGLONASS,

		/**
		* Satellite mask parameter type is track Galileo.
		*/
		TrackGalileo,

		/**
		* Satellite mask parameter type is track BeiDou.
		*/
		TrackBeiDou,

		/**
		* Satellite mask parameter type is track QZSS.
		*/
		TrackQZSS,

		/**
		* Satellite mask parameter type is track L2C.
		*/
		TrackL2C,

		/**
		* Satellite mask parameter type is track L5.
		*/
		TrackL5,

		/*
		* Satellite mask parameter type is track GPS (HW firmware 5.10 or later required)
		*/
		TrackGPS
	};
}
#endif