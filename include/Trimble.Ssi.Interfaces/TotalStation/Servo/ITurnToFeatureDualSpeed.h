#ifndef ITURNTOFEATUREDUALSPEED_H_
#define ITURNTOFEATUREDUALSPEED_H_

#include "ITurnToFeature.h"

namespace SSI
{
	/**
	* Represents an <see cref="ITurnToFeature"/> which can be created via <see cref="ISsiServo.CreateTurnToFeature"/>.
	* This Feature allows to define different servo speed values for vertical and horizontal orientation.
	* <seealso cref="ITurnToParameter"/>
	*/
	class ITurnToFeatureDualSpeed : public ITurnToFeature
	{
	public:
		virtual ~ITurnToFeatureDualSpeed();

		/**
		* Gets the vertical servo speed [Radiants/s]
		* @return the vertical angle speed.
		*/
		virtual double getVerticalAngleSpeed() const = 0;
	
		/**
		* Sets the vertical servo speed [Radiants/s]
		* @param verticalAngleSpeed in Radiants
		*/
		virtual void setVerticalAngleSpeed(double verticalAngleSpeed) = 0;

		/**
		* Gets the horizontal servo speed [Radiants/s]
		* @return the horizontal angle speed.
		*/
		virtual double getHorizontalAngleSpeed() const = 0;

		/**
		* Sets the horizontal servo speed [Radiants/s]
		* @param horizontalAngleSpeed in radiant.
		*/
		virtual void setHorizontalAngleSpeed(double horizontalAngleSpeed) = 0;

		/**
		* Gets the maximum servo speed [Radiant/s].
		* @return the maximum speed
		*/
		virtual double getMaximumSpeed() const = 0;
	};
}
#endif