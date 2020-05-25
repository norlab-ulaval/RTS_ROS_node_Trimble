#ifndef ICORRECTIONDATASOURCEDIRECTIPBASESETTINGS_H_
#define ICORRECTIONDATASOURCEDIRECTIPBASESETTINGS_H_

#include "ICorrectionDataSourceDirectIPSettings.h"
#include "ICorrectionDataSourceBaseSettings.h"

namespace SSI
{
	/**
	* Represents DirectIP reference Correction Data source settings.
	*/
	class ICorrectionDataSourceDirectIPBaseSettings : public virtual ICorrectionDataSourceDirectIPSettings ,public virtual ICorrectionDataSourceBaseSettings
	{
	public:
		virtual ~ICorrectionDataSourceDirectIPBaseSettings();
	};
}
#endif