#ifndef ILINKPARAMETERSBASSATELLITESETTINGS_H_
#define ILINKPARAMETERSBASSATELLITESETTINGS_H_

#include "ILinkParameter.h"

namespace SSI
{
	/*
	* Represents settings for establishing a connection to the SBAS Satellite..
	*/
	class ILinkParameterSBASSatelliteSettings: public ILinkParameter
	{
	public:
		virtual ~ILinkParameterSBASSatelliteSettings();
	};
}
#endif