#ifndef ISSIDATALOGSURVEY_H
#define ISSIDATALOGSURVEY_H

#include "ISsiInterface.h"
#include "ISurveyLogSession.h"
#include "SurveyMotionState.h"

namespace SSI
{
	/**
	* Provides members to access Data Logging Survey feature in GNSS receiver.
	*/
	class ISsiDataLogSurvey: public ISsiInterface
	{
	public:
		virtual ~ISsiDataLogSurvey();

		/**
		* Gets the current survey mode.
		* @return the current survey mode.
		*/
		virtual SurveyMotionState getCurrentSurveyMotionState()=0;

		/**
		* Gets the running survey log session.
		* @return The running survey log session.
		*/
		virtual ISurveyLogSession* getRunningSurveyLogSession()=0;

		/**
		* Gets the current log settings.
		* @return The current log settings.
		*/
		virtual LogSettings* getCurrentLogSettings()=0;

		/**
		* Gets the log interval.
		* @return The log interval.
		*/
		virtual double getLogInterval()=0;

		/**
		* Gets a value indicating whether logging is active.
		* @return true if logging is active; otherwise,false.
		*/
		virtual bool isLoggingActive()=0;

		/**
		* Starts the survey.
		* @param logSettings
		* @return ISurveyLogSession Container
		*/
		virtual ISurveyLogSession* startSurvey(LogSettings& logSettings)=0;

		/**
		* Ends the survey.
		*/
		virtual void endSurvey()=0;

		/**
		* Lists the supported session types.
		* @return list of supported session types
		*/
		virtual std::vector<SurveyLogSessionType> listSupportedSessionTypes()=0;

		/**
		* Determines whether the specified survey log session type is supported.
		* @param surveyLogSessionType Type of the survey log session.
		* @return true if supported.
		*/
		virtual bool isSupported(SurveyLogSessionType surveyLogSessionType)=0;

		/**
		* Lists the supported survey log parameters.
		* @param surveyLogSessionType Type of the survey log session.
		* @return list of supported parameter types.
		*/
		virtual std::vector<LogParameterType> listSupportedSurveyLogParameters(SurveyLogSessionType surveyLogSessionType)=0;

		/**
		* Determines whether the specified survey log session type is supported survey log parameter.
		* @param surveyLogSessionType Type of the survey log session.
		* @param logParameterType Type of the log parameter.
		* @return true if supported
		*/
		virtual bool isSupported(SurveyLogSessionType surveyLogSessionType, LogParameterType logParameterType)=0;

		/**
		* Creates the log parameter.
		* @param logParameterType Type of the log parameter.
		* @return
		*/
		virtual ILogParameter* createLogParameter(LogParameterType logParameterType)=0;
	};
}
#endif