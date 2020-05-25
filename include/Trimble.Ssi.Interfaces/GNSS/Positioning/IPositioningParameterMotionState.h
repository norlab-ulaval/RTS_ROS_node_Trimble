#ifndef IPOSITIONINGPARAMETERMOTIONSTATE_H_
#define IPOSITIONINGPARAMETERMOTIONSTATE_H_

#include "IPositioningParameter.h"
#include "MotionState.h"

namespace SSI
{
	/*
	* Represents positioning parameter motion state.
	* It decides whether the observations are getting enhanced by mean value calculation (static) or not.
	*/
	class IPositioningParameterMotionState: public IPositioningParameter
	{
	public:
		virtual ~IPositioningParameterMotionState();
	
		/*
		* Gets the state.
		* @return MotionState
		*/
		virtual MotionState getState()=0;

		/*
		* Sets the state.
		* @param MotionState
		*/
		virtual void setState(MotionState state)=0;
	};
}
#endif