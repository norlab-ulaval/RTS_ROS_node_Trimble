#ifndef ITURNTOPARAMETERANGLE_H_
#define ITURNTOPARAMETERANGLE_H_

#include "ITurnToParameter.h"

#include "../Common/SphericalAngles.h"

namespace SSI
{
	/**
	* turn to parameter for specific angles.
	* @see ISsiServo
	*/
	class ITurnToParameterAngle : public ITurnToParameter
	{
	public:
		virtual ~ITurnToParameterAngle();

		/**
		* get the turn to parameter type
		* @return the turn to parameter type
		*/
		TurnToParameterType getTurnToParameterType() const;

		/**
		* get the angles
		* @return the angles
		*/
		virtual SphericalAngles getAngles() const = 0;
	
		/** set the angles
		*  @param SphericalAngles the angles
		*/
		virtual void setAngles(SphericalAngles& angles) = 0;
	};
}
#endif