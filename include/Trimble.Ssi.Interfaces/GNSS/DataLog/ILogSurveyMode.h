#ifndef ILOGSURVEYMODE_H
#define ILOGSURVEYMODE_H

#include "ILogInfo.h"
#include "SurveyMode.h"

namespace SSI
{
	/**
	* Interface for accessing Log Survey Mode.
	*/
	class ILogSurveyMode: public ILogInfo
	{
	public:
		virtual ~ILogSurveyMode();
	
		/**
		* Gets the mode.
		* @return The mode.
		*/
		virtual SurveyMode getSurveyMode()=0;
	};
}
#endif