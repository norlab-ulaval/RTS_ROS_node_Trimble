#ifndef ICORRECTIONDATASOURCERADIOBASESETTINGS_H_
#define ICORRECTIONDATASOURCERADIOBASESETTINGS_H_

#include "Coordinates.h"
#include "ICorrectionDataSourceBaseSettings.h"
#include "ICorrectionDataSourceRadioSettings.h"
#include <string>

namespace SSI
{
	/** Represents Correction Data source radio base settings.
	*  @seeISsiRtkSurvey
	*/
	class ICorrectionDataSourceRadioBaseSettings : public ICorrectionDataSourceRadioSettings, public virtual ICorrectionDataSourceBaseSettings
	{
	public:
		virtual ~ICorrectionDataSourceRadioBaseSettings();
	};
}
#endif