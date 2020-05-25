#ifndef SEARCHOBSERVATIONEVENT_H_
#define SEARCHOBSERVATIONEVENT_H_

#include "TSObservationContainer.h"

namespace SSI
{
	/**
	*
	*/
	class SearchObservationsEvent
	{
	public:
		/**
		* Initializes a new instance of the <see cref="SearchObservationsEventArgs"/> class.
		* @param observation The observation.
		*/
		SearchObservationsEvent(TSObservationContainer* observation);
		virtual ~SearchObservationsEvent();

		/**
		* Gets the observations during a search <see cref="IObservationContainer"/>.
		* @return The observations as <see cref="IObservationContainer"/>.
		*/
		TSObservationContainer& getObservation() const;
	private:
		SearchObservationsEvent();
		SearchObservationsEvent(const SearchObservationsEvent& copyMe);
		//SearchObservationsEvent& operator=(const SearchObservationsEvent&);
		TSObservationContainer* _observationContainer; /** Holds the observed information. */
	};
}
#endif