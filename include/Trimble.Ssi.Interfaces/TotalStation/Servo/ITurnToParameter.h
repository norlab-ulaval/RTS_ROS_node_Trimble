#ifndef ITURNTOPARAMETER_H_
#define ITURNTOPARAMETER_H_

#include "TurnToParameterType.h"

namespace SSI
{
	/**
	* Represents a basic turn to parameter used with the ISsiServo interface.
	* @see ISsiServo
	*/
	class ITurnToParameter
	{
	public:
		virtual ~ITurnToParameter();
	
		/**
		* get the turn to parameter type
		* @return the turn to parameter type
		*/
		virtual TurnToParameterType getTurnToParameterType() const = 0;
	};
}
#endif