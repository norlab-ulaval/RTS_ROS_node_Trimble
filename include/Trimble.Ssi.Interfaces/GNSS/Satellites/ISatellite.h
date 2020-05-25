#ifndef ISATELLITE_H_
#define ISATELLITE_H_

#include "SatelliteType.h"

namespace SSI
{
	/**
	* Represents satellite instance.
	* @see ISsiSatellites
	*/
	class ISatellite
	{
	public:

		virtual ~ISatellite();

		/**
		* Gets the azimuth.
		* @return  The azimuth.
		*/
		virtual double getAzimuth() = 0;

		/**
		* Gets the elevation.
		* @return  The elevation.
		*/
		virtual double getElevation() = 0;

		/**
		* Gets a value indicating whether this @see ISatellite is enabled.
		* @return true  if enabled; otherwise, false.
		*/
		virtual bool getEnabled() = 0;

		/**
		* Gets the number.
		* @return The number.
		*/
		virtual int getNumber() = 0;

		/**
		* Gets the type of the satellite.
		* @return The type of the satellite.
		*/
		virtual SatelliteType getSatelliteType() = 0;

		/**
		* Gets a value indicating whether this @see ISatellite is used.
		* @return true if used; otherwise,false.
		*/
		virtual bool getUsed() = 0;

		/**
		* Gets the SN R1.
		* @return The SN R1.
		*/
		virtual double getSNR1() = 0;

		/**
		* Gets the SN R2.
		* @return The SN R2.
		*/
		virtual double getSNR2() = 0;

		/**
		* Gets the satellite type char.
		* @return The satellite type char.
		*/
		virtual char getSatelliteTypeChar() = 0;

		/**
		* Gets the SN R2C.
		* @return The SN R2C.
		*/
		virtual double getSNR2C() = 0;
	
		/**
		* Gets the SN R5.
		* @return The SN R5.
		*/
		virtual double getSNR5() = 0;

		virtual ISatellite& clone() = 0;
	};
}
#endif