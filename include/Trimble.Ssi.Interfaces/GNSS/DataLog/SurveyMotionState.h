#ifndef SURVEYMOTIONSTATE_H
#define SURVEYMOTIONSTATE_H

namespace SSI
{
	/**
	* Represents logging survey motion states.
	*/
	enum SurveyMotionState
	{
		/**
		* Survey is running in roving state.
		*/
		SurveyMotionState_Roving=0,

		/**
		* Survey is running in static state.
		*/
		SurveyMotionState_Static=1,

		/**
		* Survey is running in forced roving state.
		*/
		SurveyMotionState_ForceRoving=2,

		/**
		* Survey is running in fast static state.
		*/
		SurveyMotionState_FastStatic=3,

		/**
		* Survey is running in static kbi state.
		*/
		SurveyMotionState_StaticKBI=4,

		/**
		* Survey is in undefined state.
		*/
		SurveyMotionState_Undefined

	};
}
#endif
