#ifndef ISCHEDULEDSTATICSINGLESURVEYLOGSESSION_H
#define ISCHEDULEDSTATICSINGLESURVEYLOGSESSION_H

#include "IStaticSingleSurveyLogSession.h"

namespace SSI
{
	/**
	* The IStaticSingleSurveyLogSession interface provides access to scheduled single static survey log instance
	*/
	class IScheduledStaticSingleSurveyLogSession: public IStaticSingleSurveyLogSession
	{
	public:
		virtual ~IScheduledStaticSingleSurveyLogSession();
	};
}
#endif