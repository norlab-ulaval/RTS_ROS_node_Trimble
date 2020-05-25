#ifndef TRACKINGOBSERVATIONSLISTENER_H_
#define TRACKINGOBSERVATIONSLISTENER_H_

#include "TrackingObservationsEvent.h"

namespace SSI
{
	/**
	* listens for tracking observations.
	*/
	class ITrackingObservationsListener
	{
	public:
		virtual ~ITrackingObservationsListener();
	
		/**
		* process the occurred event
		* @param the event
		*/
		virtual void observationTracked(const TrackingObservationsEvent& event) = 0;
	};
}
#endif