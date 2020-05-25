#ifndef ISURVEYLOGSESSION_H_
#define ISURVEYLOGSESSION_H_

#include "LogParameterType.h"
#include "ILogParameter.h"
#include "LogSettings.h"
#include "ILogInfoListener.h"
#include "Files/ReceiverFileInfo.h"
#include <vector>

namespace SSI
{
	/**
	* The ISurveyLog interface provides access to survey log instance
	*/
	class ISurveyLogSession
	{
	public:
		virtual ~ISurveyLogSession();

		/**
		* Gets the current log settings.
		* @return The current log settings.
		*/
		virtual LogSettings* getCurrentLogSettings() = 0;

		/**
		* Gets the type of the survey log session.
		* @return The type of the survey log session.
		*/
		virtual SurveyLogSessionType getSurveyLogSessionType() = 0;

		/**
		* register a listener for listening.
		* @param ILogInfoListener to listen
		*/
		virtual void addLogInfoListener(ILogInfoListener& listener) = 0;

		/**
		* unsubscribe a listener from listening.
		* @param ILogInfoListener to listen
		*/
		virtual void removeLogInfoListener(ILogInfoListener& listener) = 0;

		/**
		* Gets the log file.
		* @return The log file.
		*/
		virtual ReceiverFileInfo* getLogFileInfo() = 0;

		/**
		* Creates log parameter based on the specified type.
		* @param logParameterType Log parameter type.
		* @return LogParameter.
		*/
		virtual ILogParameter* createSessionLogParameter(LogParameterType logParameterType) = 0;

		/**
		* Lists the supported log parameter types.
		* @return Enumerable list of parameter types.
		*/
		virtual std::vector<LogParameterType> listSupportedSessionLogParameterTypes() = 0;

		/**
		* Determines whether the specified log parameter type is supported.
		* @param logParameterType Type of the log parameter.
		* @return true if supported. Otherwise returns false.
		*/
		virtual bool isSupportedSessionLogParameterType(LogParameterType logParameterType) = 0;
	};
}
#endif