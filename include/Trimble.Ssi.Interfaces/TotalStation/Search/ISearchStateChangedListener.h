#ifndef SEARCHSTATECHANGEDLISTENER_H_
#define SEARCHSTATECHANGEDLISTENER_H_

#include "SearchStateChangedEvent.h"

namespace SSI
{
	/**
	* listens for search state changes.
	*/
	class ISearchStateChangedListener
	{
	public:
		virtual ~ISearchStateChangedListener();
	
		/**
		* process the occurred event
		* @param the event
		*/
		virtual void searchStateChanged(const SearchStateChangedEvent& event) = 0;
	};
}
#endif