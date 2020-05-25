#ifndef ITURNTOPARAMETERHORIZONTALANGLE_H_
#define ITURNTOPARAMETERHORIZONTALANGLE_H_

#include "ITurnToParameter.h"

namespace SSI
{
	/**
	* turns to a specific horizontal angle.
	* @see ISsiServo
	*/
	class ITurnToParameterHorizontalAngle : public ITurnToParameter
	{
	public:
		virtual ~ITurnToParameterHorizontalAngle();

		/**
		* get the turn to parameter type.
		* @return the turn to parameter type
		*/
		TurnToParameterType getTurnToParameterType() const;

		/**
		* get the horizontal angle.
		* @return the horizontal angle in radian
		*/
		virtual double getHorizontalAngle() const = 0;
	
		/**
		* set the horizontal angle.
		* @param double the horizontal angle
		*/
		virtual void setHorizontalAngle(double horizontalAngle) = 0;
	};
}
#endif