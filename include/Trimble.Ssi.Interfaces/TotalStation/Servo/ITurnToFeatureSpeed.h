#ifndef ITURNTOFEATURESPEED_H_
#define ITURNTOFEATURESPEED_H_

#include "ITurnToFeature.h"

namespace SSI
{
	/**
	* Represents an <see cref="ITurnToFeature"/> which can be created via <see cref="ISsiServo.CreateTurnToFeature"/>.
	* This Feature allows to define a rotation servo speed.
	* <seealso cref="ITurnToParameter"/>
	*/
	class ITurnToFeatureSpeed : public ITurnToFeature
	{
	public:
		virtual ~ITurnToFeatureSpeed();

		/**
		* Gets the rotation servo speed [Radiants/s]
		*/
		virtual double getSpeed() const = 0;
	
		/**
		* Sets the rotation servo speed [Radiants/s]
		*/
		virtual void setSpeed(double speed) = 0;

		/**
		* Gets the maximum servo speed [Radiants/s]
		*/
		virtual double getMaximumSpeed() const = 0;
	};
}
#endif