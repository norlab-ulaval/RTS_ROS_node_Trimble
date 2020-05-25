#ifndef SEARCHOBSERVATIONSLISTENER_H_
#define SEARCHOBSERVATIONSLISTENER_H_

#include "SearchObservationsEvent.h"

namespace SSI
{
	/**
	* listens for search observations.
	*/
	class ISearchObservationsListener
	{
	public:
		virtual ~ISearchObservationsListener();
	
		/**
		* process the occurred event
		* @param the event
		*/
		virtual void observationSearch(const SearchObservationsEvent& event) = 0;
	};
}
#endif