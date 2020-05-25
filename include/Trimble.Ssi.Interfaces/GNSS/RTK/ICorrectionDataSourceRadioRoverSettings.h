#ifndef ICORRECTIONDATASOURCERADIOROVERSETTINGS_H_
#define ICORRECTIONDATASOURCERADIOROVERSETTINGS_H_

#include "ICorrectionDataSourceRadioSettings.h"

namespace SSI
{
	/**
	* Represents correction data source radio rover settings.
	*
	* @see ISsiRTKSurvey
	*/
	class ICorrectionDataSourceRadioRoverSettings : public ICorrectionDataSourceRadioSettings
	{
	public:
		virtual ~ICorrectionDataSourceRadioRoverSettings();

		/**
		* Gets the index of the base station.
		* @return The index of the base station.
		* @remarks Negative value will match any base station index
		*/
		virtual short getBaseStationIndex() const=0;
	
		/**
		* Sets the index of the base station.
		* @param baseStationIndex The index of the base station.
		* @remarks Negative value will match any base station index
		*/
		virtual void setBaseStationIndex(short baseStationIndex)=0;
	};
}
#endif