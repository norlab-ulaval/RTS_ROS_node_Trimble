#ifndef SURVEYSTATEUPDATE_H_
#define SURVEYSTATEUPDATE_H_

#include "SurveyState.h"

namespace SSI
{
	/*
	* Provides data for the Survey state update
	*/
	class SurveyStateUpdate
	{
	public:
		/*
		* Initializes a new instance of the <see cref="SurveyStateChangedEventArgs"/> class.
		* @param SurveyState
		*/
		SurveyStateUpdate(SurveyState surveyState);

		/*
		* Gets the state of the survey.
		* @return SurveyState
		*/
		SurveyState getSurveyState() const;
	private:
		SurveyState _surveyState;
	};
}
#endif