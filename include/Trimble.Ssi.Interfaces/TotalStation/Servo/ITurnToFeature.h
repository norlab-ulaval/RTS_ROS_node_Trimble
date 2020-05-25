#ifndef ITURNTOFEATURE_H_
#define ITURNTOFEATURE_H_

#include "TurnToFeatureType.h"

namespace SSI
{
	/**
	* Represents a basic turn to features used with an <see cref="ITurnToParameter"/> implementation.
	* You can create instance of this interface through <see cref="ISsiServo.CreateTurnToFeature"/> by passing an <see cref="TurnToFeatureType"/>.
	* See <see cref="ISsiServo.ListSupportedTurnToFeatureTypes"/> for a list of available <see cref="TurnToFeatureType"/> values.
	* <seealso cref="ISsiServo"/>
	*/
	class ITurnToFeature
	{
	public:
		virtual ~ITurnToFeature();
	
		/**
		* Gets the type of this turn to feature.
		* @return the  turn to feature type.
		*/
		virtual TurnToFeatureType getType() const = 0;
	};
}
#endif