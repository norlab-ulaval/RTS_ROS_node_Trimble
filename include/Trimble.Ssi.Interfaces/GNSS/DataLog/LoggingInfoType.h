#ifndef LOGGINGINFOTYPE_H_
#define LOGGINGINFOTYPE_H_

namespace SSI
{
	/**
	* Defines LoggingInfoType constant objects
	*/
	enum LoggingInfoType
	{
		/**
		* The logging state
		*/
		LogInfo_LogState,

		/**
		* The logging time
		*/
		LogInfo_LoggingTime,

		/**
		* The log time automatic go
		*/
		LogInfo_LogTimeToGo,

		/**
		* The log start time.
		*/
		LogInfo_LogStartTime,

		/**
		* The log file
		*/
		LogInfo_LogFileInfo,

		/**
		* The survey motion state.
		*/
		LogInfo_SurveyMotionState,

		/**
		* The survey mode
		*/
		LogInfo_SurveyMode,

		/**
		* The session state
		*/
		LogInfo_SessionState,

		/**
		* The survey type
		*/
		LogInfo_SurveyType,

		/**
		* The available memory.
		*/
		LogInfo_AvailableMemory,

		/**
		* The fast static logging time
		*/
		LogInfo_LoggingTimeFastStatic,

		/**
		* The session name
		*/
		LogInfo_SessionName,

		/**
		* The point name
		*/
		LogInfo_PointName,

		/**
		* The antenna height
		*/
		LogInfo_AntennaHeight,

		/**
		* The elevation mask
		*/
		LogInfo_ElevationMask,

		/**
		* The static epochs.
		*/
		LogInfo_StaticEpochs,

		/**
		* The interval.
		*/
		LogInfo_EpochInterval,

		/**
		* The antenna.
		*/
		LogInfo_Antenna,

        /**
        * The post processing assessment.
        */
        LogInfo_PostProcessingAssessment
	};
}
#endif