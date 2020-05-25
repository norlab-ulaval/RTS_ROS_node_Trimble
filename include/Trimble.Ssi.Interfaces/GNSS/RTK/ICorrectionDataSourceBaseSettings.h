#ifndef ICORRECTIONDATASOURCEBASESETTINGS_H_
#define ICORRECTIONDATASOURCEBASESETTINGS_H_

#include "ICorrectionDataSourceAdvanced.h"
#include "Coordinates.h"
#include <string>

namespace SSI
{
	/**
	*  Represents general reference Correction Data source settings.
	*/
	class ICorrectionDataSourceBaseSettings : public virtual ICorrectionDataSourceAdvanced
	{
	public:
		virtual ~ICorrectionDataSourceBaseSettings();

		/**
		* Gets the coordinates.
		* @return  The coordinates.
		*/
		virtual const Coordinates& getCoordinates() const=0;

		/**
		* Sets the coordinates.
		* @param coordinates The coordinates.
		*/
		virtual void setCoordinates(Coordinates coordinates)=0;

		/**
		* Gets the height of the antenna.
		* @return  The height of the antenna.
		*/
		virtual double getAntennaHeight() const=0;

		/**
		* Sets the height of the antenna.
		* @param antennaHeight  The height of the antenna.
		*/
		virtual void setAntennaHeight(double antennaHeight)=0;

		/**
		* Gets the name.
		* @return  The name.
		*/
		virtual const std::string& getName() const=0;

		/**
		* Sets the name.
		* @param name  The name.
		*/
		virtual void setName(std::string name)=0;

		/**
		* Gets the code.
		* @return  The code.
		*/
		virtual const std::string& getCode() const=0;

		/**
		* Sets the code.
		* @param code  The code.
		*/
		virtual void setCode(std::string code)=0;

		/**
		* Gets the index of the base station.
		* @return  The index of the base station.
		*/
		virtual short getStationIndex() const=0;

		/**
		* Sets the index of the base station.
		* @param stationIndex  The index of the base station.
		*/
		virtual void setStationIndex(short stationIndex)=0;
	};
}
#endif