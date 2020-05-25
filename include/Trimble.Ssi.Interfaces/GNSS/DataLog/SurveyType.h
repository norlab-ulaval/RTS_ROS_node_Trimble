#ifndef SURVEYTYPE_H
#define SURVEYTYPE_H

namespace SSI
{
	/**
	* Represents logging survey types.
	*/
	enum SurveyType
	{
		/**
		* No survey is running.
		*/
		SurveyType_NoSurvey=0,

		/**
		* Static survey.
		*/
		SurveyType_Static=1,

		/**
		* Fast static survey.
		*/
		SurveyType_FastStatic=2,

		/**
		* Continues Kinematic Survey.
		*/
		SurveyType_ContKinematic=3
	};
}
#endif