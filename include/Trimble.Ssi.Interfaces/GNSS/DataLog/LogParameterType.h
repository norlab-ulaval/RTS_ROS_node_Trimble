#ifndef LOGPARAMETERTYPE_H_
#define LOGPARAMETERTYPE_H_

namespace SSI
{
	/**
	* Defines constant LogParameter Type objects
	*/
	enum LogParameterType
	{
        /**
        * Log file parameter.
        */
        LogParameterType_LogFile,

		/**
		* Log duration parameter.
		*/
		LogParameterType_LogDuration,

		/**
		* Log antenna height parameter.
		*/
		LogParameterType_LogAntennaHeight,

		/**
		* Log point name parameter.
		*/
		LogParameterType_LogPointName,

		/**
		* Log point code parameter.
		*/
		LogParameterType_LogPointCode,

		/**
		* Log interval parameter.
		*/
		LogParameterType_LogInterval,

		/**
		* Log start time
		*/
		LogParameterType_LogStartTime,

		/**
		* Log fast static times
		*/
		LogParameterType_LogFastStaticTime,

		/**
		* Log diagnostics
		*/
        LogParameterType_LogDiagnostic,
	};
}
#endif