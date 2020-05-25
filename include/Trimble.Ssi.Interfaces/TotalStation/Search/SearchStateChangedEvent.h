#ifndef SEARCHSTATECHANGEDEVENT_H_
#define SEARCHSTATECHANGEDEVENT_H_

#include "SearchState.h"

namespace SSI
{
	/**
	* Provides data for the <see cref="ISsiSearch.SearchStateChanged"/> event.
	* <seealso cref="ISsiSearch.SearchStateChanged"/>
	* <seealso cref="ISsiSearch"/>
	*/
	class SearchStateChangedEvent
	{
	public:
		/**
		* Initializes a new instance of the <see cref="SearchStateChangedEventArgs"/> class.
		* @param searchState The current search state.
		*/
		SearchStateChangedEvent(SearchState searchState);
		virtual ~SearchStateChangedEvent();

		/**
		* Gets the current search state.
		* @return The current search state.
		*/
		SearchState getSearchState() const;
	private:
		SearchStateChangedEvent();
		SearchStateChangedEvent(const SearchStateChangedEvent& copyMe);
		//SearchStateChangedEvent& operator=(const SearchStateChangedEvent&);
		SearchState _searchState;
	};
}
#endif