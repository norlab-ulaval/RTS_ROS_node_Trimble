#ifndef ILINKPARAMETERINTERNALBLUETOOTHSETTINGS_H_
#define ILINKPARAMETERINTERNALBLUETOOTHSETTINGS_H_

#include "ILinkParameter.h"

namespace SSI
{
	/**
	* Represents link parameter internal Bluetooth settings.
	* @see ISsiRTKSurvey
	*/
	class ILinkParameterInternalBluetoothSettings :public ILinkParameter
	{
	public:
		virtual ~ILinkParameterInternalBluetoothSettings();
	};
}
#endif