#ifndef ITIMEOBSERVATION_H_
#define ITIMEOBSERVATION_H_

#include "ITSObservation.h"

namespace SSI
{
	/**
	* Represents a time stamp.
	* <seealso cref="IObservationContainer"/>
	* <seealso cref="ISsiMeasurement"/>
	* <seealso cref="ISsiTracking"/>
	*/
	class ITimeObservation : public ITSObservation
	{
	public:
		virtual ~ITimeObservation();

		/**
		* Gets the time of the synchronized measurement in UTC.
		* @return UTC Time of the synchronized measurement.
		*/
		virtual double getTimeUtc() const = 0;
	};
}
#endif