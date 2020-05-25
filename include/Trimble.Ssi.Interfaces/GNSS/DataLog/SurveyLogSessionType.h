#ifndef SURVEYLOGSESSIONTYPE_H_
#define SURVEYLOGSESSIONTYPE_H_

namespace SSI
{
	/**
	* Defines constant SurveyLogSession Type objects
	*/
	enum SurveyLogSessionType
	{
		/**
		* Single Static survey.
		*/
		SurveyLogSessionType_StaticSingle,

		/**
		* Scheduled Single Static survey.
		*/
		SurveyLogSessionType_ScheduledStaticSingle,

		/**
		* Multi Fast Static survey.
		*/
		SurveyLogSessionType_FastStatic,

		/**
		* Check Logging.
		*/
		SurveyLogSessionType_Check,

		/**
		* Continue single Static survey.
		*/
		SurveyLogSessionType_Continue,
	};
}
#endif
