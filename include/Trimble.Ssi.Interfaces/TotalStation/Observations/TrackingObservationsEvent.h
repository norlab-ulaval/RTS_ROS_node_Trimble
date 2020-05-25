#ifndef TRACKINGOBSERVATIONSEVENT_H_
#define TRACKINGOBSERVATIONSEVENT_H_

#include "TSObservationContainer.h"
#include "InvalidTrackingObservationsException.h"

namespace SSI
{
	/** Provides data for the ISsiTracking.NewTrackingObservations event.
	* @see ISsiTracking.NewTrackingObservations
	* @see ISsiTracking
	*/
	class TrackingObservationsEvent
	{
	public:
	
		/**
		* Initializes a new instance of the TrackingObservationsEventArgs class.
		* @param ObservationContainer The measurement.
		*/
		TrackingObservationsEvent(TSObservationContainer& observationContainer, InvalidTrackingObservationsException* exception = 0);
		virtual ~TrackingObservationsEvent();

		/**
		* Gets the tracked observations as an ObservationContainer.
		* @returns The observations as ObservationContainer.
		*/
		TSObservationContainer& getObservationContainer() const;

		/**
		* Gets the tracked observations as an ObservationContainer. Do not throw exception.
		* @returns The observations as ObservationContainer.
		*/
		TSObservationContainer& getObservationContainerNoThrow() const;

		/**
		* Gets the Exception.
		* @returns The Exception.
		*/
		InvalidTrackingObservationsException* getException() const;
	private:
		TrackingObservationsEvent();
		TrackingObservationsEvent(const TrackingObservationsEvent& copyMe);
		TrackingObservationsEvent& operator=(const TrackingObservationsEvent&);
		TSObservationContainer& _observationContainer; /** Holds the observed information. */
		InvalidTrackingObservationsException* _exception;
	};
}
#endif