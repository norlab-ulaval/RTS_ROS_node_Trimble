#ifndef ISURVEYSTATELISTENER_H_
#define ISURVEYSTATELISTENER_H_

#include "SurveyStateUpdate.h"

namespace SSI
{
	/**
	* Listens for changed survey state.
	*/
	class ISurveyStateListener
	{
	public:
		virtual ~ISurveyStateListener();

		/**
		* receives the event message when changes occur.
		* @param NtripConnectionStatusUpdate that occurred
		*/
		virtual void onSurveyStateChanged(const SurveyStateUpdate& surveyStateUpdate) = 0;
	};
}
#endif