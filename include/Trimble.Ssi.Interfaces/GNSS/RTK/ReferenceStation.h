#ifndef REFERENCESTATION_H_
#define REFERENCESTATION_H_

#include "AdvancedBaseData.h"
#include "Coordinates.h"

namespace SSI
{
	/*
	* Represents a RTK reference station instance.
	*/
	class ReferenceStation
	{
	public:
		/*
		* Initializes a new instance of the <see cref="ReferenceStation"/> class.
		* @param Coordinates
		* @param std::string
		* @param int
		* @param double
		* @param AdvancedBaseData
		*/
		ReferenceStation(Coordinates& coordinates, std::string name, int id, double antennaHeight, AdvancedBaseData& advancedBaseData);

		/*
		* Initializes a new instance of the <see cref="ReferenceStation"/> class.
		* @param Coordinates
		* @param std::string
		* @param int
		* @param double
		*/
		ReferenceStation(Coordinates& coordinates, std::string name, int id, double antennaHeight);

		/*
		* Initializes a new instance of the <see cref="ReferenceStation"/> class.
		* @param ReferenceStation&
		*/
		ReferenceStation(const ReferenceStation& assignMe);

		/*
		* Gets the coordinates.
		* @return Coordinates
		*/
		Coordinates getCoordinates();

		/*
		* Gets the name.
		* @return std::string
		*/
		std::string getName();

		/*
		* Gets the ID.
		* @return int
		*/
		int getID();

		/*
		* Gets the height of the antenna.
		* @return double
		*/
		double getAntennaHeight();

		/*
		* Gets the radio base data.
		* @return AdvancedBaseData
		*/
		AdvancedBaseData getAdvancedBaseData();

		ReferenceStation& operator=(const ReferenceStation& assignMe);

		bool hasAdvancedBaseData();

	private:
		Coordinates _coordinates;
		std::string _name;
		int _id;
		double _antennaHeight;
		bool _hasAdvancedBaseData;
		AdvancedBaseData _advancedBaseData;
	};
}
#endif