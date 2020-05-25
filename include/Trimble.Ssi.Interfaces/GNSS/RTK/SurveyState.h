#ifndef SURVEYSTATE_H_
#define SURVEYSTATE_H_

namespace SSI
{
	/*
	* Represents the current RTK survey state.
	* @remark The value of ISsiRtkSurvey.SurveyState will be one of these values.
	*/
	enum SurveyState
	{
		/*
		* Survey state is not running.
		*/
		SurveyState_NotRunning,

		/*
		* Survey state is starting.
		*/
		SurveyState_Starting,

		/*
		* Survey state is running.
		*/
		SurveyState_Running,

		/*
		* Survey state is ending.
		*/
		SurveyState_Ending,

		/*
		* Survey state is link down.
		*/
		SurveyState_LinkDown
	};
}
#endif