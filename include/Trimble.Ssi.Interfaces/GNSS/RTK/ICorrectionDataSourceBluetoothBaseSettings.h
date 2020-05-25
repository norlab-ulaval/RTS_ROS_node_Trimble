#ifndef ICORRECTIONDATASOURCEBLUETOOTHBASESETTINGS_H_
#define ICORRECTIONDATASOURCEBLUETOOTHBASESETTINGS_H_

#include "ICorrectionDataSourceBaseSettings.h"
#include "ICorrectionDataSourceBluetoothSettings.h"

namespace SSI
{
	/**
	*  Represents correction data source Bluetooth base settings.
	*  @see ISsiRTKSurvey
	*/
	class ICorrectionDataSourceBluetoothBaseSettings : public ICorrectionDataSourceBluetoothSettings, public virtual ICorrectionDataSourceBaseSettings
	{
	public:
		virtual ~ICorrectionDataSourceBluetoothBaseSettings();
	};
}
#endif