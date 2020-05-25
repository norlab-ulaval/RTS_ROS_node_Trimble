#ifndef TURNTOPARAMETERTYPE_H_
#define TURNTOPARAMETERTYPE_H_

namespace SSI
{
	/**
	* Represents the type of a turn to parameter.
	* To get an enumeration of supported TurnToParameterType values, use ISsiServo::ListSupportedTurnToParameterTypes.
	* Use ISsiServo::CreateTurnToParameter to create an ITurnToParameter based on the TurnToParameterType.
	*/
	enum TurnToParameterType
	{
		TTPT_Angle,				/**< use horizontal and vertical angles. */
		TTPT_HorizontalAngle,	/**< use only horizontal angle. */
		TTPT_VerticalAngle		/**< use only vertical angle. */
	};
}
#endif