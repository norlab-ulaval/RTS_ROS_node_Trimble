#ifndef ICORRECTIONDATASOURCERADIOSETTINGS_H_
#define ICORRECTIONDATASOURCERADIOSETTINGS_H_

#include "ICorrectionDataSourceAdvanced.h"

namespace SSI
{
	/**
	*  Represents correction data source radio settings.
	*  @see ISsiRTKSurvey
	*/
	class ICorrectionDataSourceRadioSettings : public virtual ICorrectionDataSourceAdvanced
	{
	public:
		virtual ~ICorrectionDataSourceRadioSettings();
	};
}
#endif