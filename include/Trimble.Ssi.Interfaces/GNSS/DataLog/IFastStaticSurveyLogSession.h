#ifndef IFASTSTATICSURVEYLOGSESSION_H_
#define IFASTSTATICSURVEYLOGSESSION_H_

#include "LogSettings.h"
#include "ISurveyLogSession.h"

namespace SSI
{
	/**
	* The IFastStaticSurveyLogSession interface provides access to multi FastStaticPoint survey log instance
	*/
	class IFastStaticSurveyLogSession: public virtual ISurveyLogSession
	{
	public:
		virtual ~IFastStaticSurveyLogSession();
	
		/**
		* Starts the measurement.
		* @param measureLogSettings
		*/
		virtual void startMeasurement(LogSettings& measureLogSettings)=0;

		/**
		* Cancels the measurement.
		*/
		virtual void cancelMeasurement(LogSettings& measureLogSettings)=0;

		/**
		* Stores the fast static FastStaticPoint.
		*/
		virtual void storeMeasurement(LogSettings& measureLogSettings)=0;
	};
}
#endif