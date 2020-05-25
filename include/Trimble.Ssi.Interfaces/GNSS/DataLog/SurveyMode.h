#ifndef SURVEYMODE_H
#define SURVEYMODE_H

namespace SSI
{
	/**
	* Represents logging survey modes.
	*/
	enum SurveyMode
	{
		/**
		* No survey is running.
		*/
		SurveyMode_NoSurvey=0,

		/**
		* Auto Survey
		*/
		SurveyMode_Auto=1,

		/**
		* Manual Survey.
		*/
		SurveyMode_Manual=2,

		/**
		* Scheduled Survey.
		*/
		SurveyMode_Scheduled=3
	};
}
#endif
