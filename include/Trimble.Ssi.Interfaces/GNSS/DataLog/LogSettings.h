#ifndef LOGSETTINGS_H_
#define LOGSETTINGS_H_

#include "ILogParameter.h"
#include "SurveyLogSessionType.h"
#include <map>

namespace SSI
{
	/**
	* Represents log settings.
	*/
	class LogSettings
	{
	public:
		/**
		* Gets the type of the log session.
		* @return The type of the log session.
		*/
		SurveyLogSessionType getLogSessionType();

		/**
		* Sets the type of the log session.
		* @return The type of the log session.
		*/
		void setLogSessionType(SurveyLogSessionType logSessionType);

		/**
		* Initializes a new instance of the @see LogSettings class.
		*/
		LogSettings(SurveyLogSessionType logSessionType);

		/**
		* Gets the log parameter.
		* @param logParameterType Type of the log parameter.
		* @return LogParameter for the specified type
		*/
		ILogParameter* getLogParameter(LogParameterType logParameterType);

		/**
		* Determines whether the @see LogSettings containes specified log parameter type.
		* @param logParameterType Type of the log parameter.
		* @return true - when it has Log parameter otherwise returns false
		*/
		bool hasLogParameter(LogParameterType logParameterType);

		/**
		* Adds the specified log parameter.
		* @param logParameter The log parameter.
		*/
		void add(ILogParameter* logParameter);
	private:
		SurveyLogSessionType _logSessionType;
		std::map<LogParameterType,ILogParameter*> _map;
	};
}
#endif
