#ifndef ILOGSURVEYTYPE_H
#define ILOGSURVEYTYPE_H

#include "ILogInfo.h"
#include "SurveyType.h"

namespace SSI
{
	/**
	* Interface for accessing Log Survey Type.
	*/
	class ILogSurveyType: public ILogInfo
	{
	public:
		virtual ~ILogSurveyType();
	
		/**
		* Gets the survey type.
		* @return The survey type.
		*/
		virtual SurveyType getSurveyType()=0;
	};
}
#endif