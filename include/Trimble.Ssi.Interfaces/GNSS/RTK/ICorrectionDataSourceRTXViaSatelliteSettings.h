#ifndef ICORRECTIONDATASOURCERTXVIASATELLITESETTINGS_H_
#define ICORRECTIONDATASOURCERTXVIASATELLITESETTINGS_H_

#include "ICorrectionDataSource.h"
#include "TectonicPlateInfo.h"
#include "Coordinates.h"
#include "ReferenceFrame.h"
#include <vector>

namespace SSI
{
	/**
	* Represents Settings for establishing an RTX Via Satellite Connection.
	*/
	class ICorrectionDataSourceRTXViaSatelliteSettings : public virtual ICorrectionDataSource
	{
	public:
		virtual ~ICorrectionDataSourceRTXViaSatelliteSettings();
		
	};
}
#endif
