#ifndef TRACKINGSTATECHANGEDEVENT_H_
#define TRACKINGSTATECHANGEDEVENT_H_

#include "TrackingState.h"

namespace SSI
{
	/**
	* Provides data for the <see cref="ISsiTracking.TrackingStateChanged"/> event.
	* <seealso cref="ISsiTracking.TrackingStateChanged"/>
	*/
	class TrackingStateChangedEvent
	{
	public:
		/**
		* Initializes a new instance of the <see cref="TrackingStateChangedEvent"/> class.
		* @param trackingState The trackingtrackingstate.
		*/
		TrackingStateChangedEvent(TrackingState trackingState);
		virtual ~TrackingStateChangedEvent();

		/**
		* Gets the state of the attribute tracking.
		* @return The state of the attribute tracking.
		*/
		TrackingState getTrackingState() const;
	private:
		TrackingStateChangedEvent();
		TrackingStateChangedEvent(const TrackingStateChangedEvent& copyMe);
		//TrackingStateChangedEvent& operator=(const TrackingStateChangedEvent&);
		TrackingState _trackingState;
	};
}
#endif