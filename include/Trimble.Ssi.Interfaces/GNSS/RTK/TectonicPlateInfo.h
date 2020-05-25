#ifndef TECTONICPLATEINFO_H_
#define TECTONICPLATEINFO_H_

#include "TectonicPlate.h"

namespace SSI
{
	/**
	* Represents Tectonic Plate information.
	*/
	class TectonicPlateInfo
	{
	public:
		TectonicPlateInfo();
		TectonicPlateInfo(TectonicPlate tectonicPlate, double distance, bool inside);

		/**
		* Gets the tectonic plate.
		* @return The tectonic plate.
		*/
		TectonicPlate getTectonicPlate();

		/**
		* Sets the tectonic plate.
		* @param tectonicPlate The tectonic plate.
		*/
		void setTectonicPlate(TectonicPlate tectonicPlate);

		/**
		* Gets value indicating whether the current location is inside or outside the Tectonic plate.
		* @return true if inside; otherwise, false.
		*/
		bool getInside();

		/**
		* Sets value indicating whether the current location is inside or outside the Tectonic plate.
		* @param inside true if inside; otherwise, false.
		*/
		void setInside(bool inside);
		
		/**
		* Gets the distance.
		* @return The distance.
		*/
		double getDistance();

		/**
		* Sets the distance.
		* @param distance The distance.
		*/
		void setDistance(double distance);
	private:
		TectonicPlate _tectonicPlate;
		bool _inside;
		double _distance;
	};
}
#endif