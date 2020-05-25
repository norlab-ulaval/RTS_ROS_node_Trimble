#ifndef ILOGSURVEYMOTIONSTATE_H
#define ILOGSURVEYMOTIONSTATE_H

#include "ILogInfo.h"
#include "SurveyMotionState.h"

namespace SSI
{
	/**
	* Interface for accessing Log Survey Motion State.
	*/
	class ILogSurveyMotionState: public ILogInfo
	{
	public:
		virtual ~ILogSurveyMotionState();
	
		/**
		* Gets the motion state.
		* @return The Motion state.
		*/
		virtual SurveyMotionState getSurveyMotionState()=0;
	};
}
#endif