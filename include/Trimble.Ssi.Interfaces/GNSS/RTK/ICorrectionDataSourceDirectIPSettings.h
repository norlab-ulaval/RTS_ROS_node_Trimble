#ifndef ICORRECTIONDATASOURCEDIRECTIPSETTINGS_H_
#define ICORRECTIONDATASOURCEDIRECTIPSETTINGS_H_

#include "ICorrectionDataSourceAdvanced.h"
#include "ICorrectionDataSourceTCPSettings.h"
#include <string>

namespace SSI
{
	/**
	* Represents correction data source Direct IP settings.
	*
	* @see ISsiRtkSurvey
	*/
	class ICorrectionDataSourceDirectIPSettings : public ICorrectionDataSourceTCPSettings, public virtual ICorrectionDataSourceAdvanced
	{
	public:
		virtual ~ICorrectionDataSourceDirectIPSettings();
	};
}
#endif
