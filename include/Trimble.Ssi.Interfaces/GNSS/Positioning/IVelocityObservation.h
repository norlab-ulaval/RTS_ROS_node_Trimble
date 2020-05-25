#ifndef IVELOCITYOBSERVATION_H
#define IVELOCITYOBSERVATION_H

#include "IGNSSObservation.h"

namespace SSI
{
	/**
	* Represents a velocity observation.
	* @see IObservationContainer
	* @see ISsiPositioning
	*/
	class IVelocityObservation : public IGNSSObservation
	{
	public:
		virtual ~IVelocityObservation();
		
		/**
		* Gets the heading.
		* @return The heading is the WGS84 referenced true north heading in radians.
		*/
		virtual double getHeading() const = 0;

		/**
		* Gets the horizontal velocity.
		* @return The horizontal velocity in meters per second. 
		*/
		virtual double getHorizontal() const = 0;

		/**
		* Gets the vertical velocity.
		* @return The vertical velocity in meters per second.
		*/
		virtual double getVertical() const = 0;
	};
}
#endif