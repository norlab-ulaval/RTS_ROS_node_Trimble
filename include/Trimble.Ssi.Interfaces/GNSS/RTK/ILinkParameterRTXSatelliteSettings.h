#ifndef ILINKPARAMETERRTXSATELLITESETTINGS_H_
#define ILINKPARAMETERRTXSATELLITESETTINGS_H_

#include "ILinkParameter.h"

namespace SSI
{
	/*
	* Represents settings for establishing a connection to the RTX Satellite..
	*/
	class ILinkParameterRTXSatelliteSettings: public ILinkParameter
	{
	public:
		virtual ~ILinkParameterRTXSatelliteSettings();
	};
}
#endif