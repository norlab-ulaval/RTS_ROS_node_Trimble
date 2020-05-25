#ifndef ILINKPARAMETERRADIOSETTINGS_H_
#define ILINKPARAMETERRADIOSETTINGS_H_

#include "ILinkParameter.h"

namespace SSI
{
	/**
	* Represents link parameter radio settings.
	* @see ISsiRTKSurvey
	*/
	class ILinkParameterRadioSettings :public ILinkParameter
	{
	public:
		virtual ~ILinkParameterRadioSettings();
	};
}
#endif