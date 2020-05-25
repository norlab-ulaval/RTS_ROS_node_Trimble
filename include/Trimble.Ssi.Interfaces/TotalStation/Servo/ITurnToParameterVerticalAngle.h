#ifndef ITURNTOPARAMETERVERTICALANGLE_H_
#define ITURNTOPARAMETERVERTICALANGLE_H_

#include "ITurnToParameter.h"

namespace SSI
{
	/**
	* turns to a specific vertical angle.
	* @see ISsiServo
	*/
	class ITurnToParameterVerticalAngle : public ITurnToParameter
	{
	public:
		virtual ~ITurnToParameterVerticalAngle();

		/**
		* get the turn to parameter type.
		* @return the turn to parameter type
		*/
		TurnToParameterType getTurnToParameterType() const;

		/**
		* get the vertical angle.
		* @return the vertical angle
		*/
		virtual double getVerticalAngle() const = 0;
	
		/**
		* set the vertical angle.
		* @param double the vertical angle
		*/
		virtual void setVerticalAngle(double verticalAngle) = 0;
	};
}
#endif