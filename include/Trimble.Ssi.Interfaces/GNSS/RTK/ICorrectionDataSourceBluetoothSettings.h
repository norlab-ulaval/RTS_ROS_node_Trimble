#ifndef ICORRECTIONDATASOURCEBLUETOOTHSETTINGS_H_
#define ICORRECTIONDATASOURCEBLUETOOTHSETTINGS_H_

#include "ICorrectionDataSourceAdvanced.h"

namespace SSI
{
	/**
	*  Represents correction data source Bluetooth settings.
	*  @see ISsiRTKSurvey
	*/
	class ICorrectionDataSourceBluetoothSettings : public virtual ICorrectionDataSourceAdvanced
	{
	public:
		virtual ~ICorrectionDataSourceBluetoothSettings();
	};
}
#endif