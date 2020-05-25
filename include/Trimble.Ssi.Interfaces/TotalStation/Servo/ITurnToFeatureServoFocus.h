#ifndef ITURNTOFEATURESERVOFOCUS_H_
#define ITURNTOFEATURESERVOFOCUS_H_

#include "ITurnToFeature.h"

namespace SSI
{
	/**
	* Represents an <see cref="ITurnToFeature"/> which can be created via <see cref="ISsiServo.CreateTurnToFeature"/>.
	* This Feature allows to define a slope distance the telescope will automatically focus on.
	* <seealso cref="ITurnToParameter"/>
	*/
	class ITurnToFeatureServoFocus : public ITurnToFeature
	{
	public:
		virtual ~ITurnToFeatureServoFocus();

		/**
		* Gets the slope distance to focus on.
		* @return The slope distance.
		*/
		virtual double getSlopeDistance() const = 0;

		/**
		* Sets the slope distance to focus on.
		* @param slopeDistance The slope distance.
		*/
		virtual void setSlopeDistance(double slopeDistance) = 0;
	};
}
#endif