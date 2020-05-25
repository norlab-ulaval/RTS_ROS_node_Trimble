#ifndef ICORRECTIONDATASOURCENTRIPWITHVRSPOSITIONSETTINGS_H_
#define ICORRECTIONDATASOURCENTRIPWITHVRSPOSITIONSETTINGS_H_

#include "ICorrectionDataSourceNTRIPSettings.h"
#include "Coordinates.h"

namespace SSI
{
	/*
	* Represents correction data source NTRIP with VRS position settings.
	*/
	class ICorrectionDataSourceNTRIPWithVRSPositionSettings : public virtual ICorrectionDataSourceNTRIPSettings
	{
	public:
		virtual ~ICorrectionDataSourceNTRIPWithVRSPositionSettings();

		/*
		* Gets the coordinates.
		* 
		* @return The coordinates.
		*/
		virtual const Coordinates& getCoordinates() const=0;

		/*
		* Sets the coordinates.
		* 
		* @param coordinates The coordinates.
		*/
		virtual void setCoordinates(Coordinates coordinates)=0;
	};
}
#endif
