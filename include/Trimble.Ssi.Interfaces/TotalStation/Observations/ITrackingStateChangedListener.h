#ifndef TRACKINGSTATECHANGEDLISTENER_H_
#define TRACKINGSTATECHANGEDLISTENER_H_

#include "TrackingStateChangedEvent.h"

namespace SSI
{
	/**
	* listens for tracking state changes.
	*/
	class ITrackingStateChangedListener
	{
	public:
		virtual ~ITrackingStateChangedListener();

		/**
		* process the occurred event
		* @param the event
		*/
		virtual void trackingStateChanged(const TrackingStateChangedEvent& event) = 0;
	};
}
#endif