#ifndef TURNTOFEATURETYPE_H_
#define TURNTOFEATURETYPE_H_

namespace SSI
{
	/**
	* Represents the type of a turn to feature.
	* To get an enumeration of supported <see cref="TurnToFeatureType"/> values, use <see cref="ISsiServo.ListSupportedTurnToFeatureTypes"/>.
	* Use <see cref="ISsiServo.CreateTurnToFeature"/> to create an <see cref="ITurnToFeature"/> based on the <see cref="TurnToFeatureType"/>.
	*/
	enum TurnToFeatureType
	{
		/**
		* A type of a turn-to features which allows to change the rotation speed of a turn to procedure.
		* A turn to feature of this type will always implement the <see cref="ITurnToFeatureSpeed"/> interface.
		*/
		TTFT_Speed,

		/**
		* A type of a turn-to features which allows to change the vertical and horizontal speed of a turn to procedure.
		* A turn to feature of this type will always implement the <see cref="ITurnToFeatureDualSpeed"/> interface.
		*/
		TTFT_DualSpeed,

		/**
		* A type of a turn-to features which allows to set the slope distance the telescope should automatically focus on.
		* A turn to feature of this type will always implement the <see cref="ITurnToFeatureServoFocus"/> interface.
		*/
		TTFT_ServoFocus
	};
}
#endif