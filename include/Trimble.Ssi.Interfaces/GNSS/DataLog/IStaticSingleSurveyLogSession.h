#ifndef ISTATICSINGLESURVEYLOGSESSION_H
#define ISTATICSINGLESURVEYLOGSESSION_H

#include "ISurveyLogSession.h"

namespace SSI
{
	/**
	* The IStaticSingleSurveyLogSession interface provides access to single static survey log instance.
	*/
	class IStaticSingleSurveyLogSession: public virtual ISurveyLogSession
	{
	public:
		virtual ~IStaticSingleSurveyLogSession();
	};
}
#endif