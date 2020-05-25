#ifndef SEARCHSTATE_H_
#define SEARCHSTATE_H_

namespace SSI
{
	/**
	* Represents the state of a search sensor.
	* <seealso cref="ISsiSearch"/>
	*/
	enum SearchState
	{
		SS_Searching,	/**< The searching */
		SS_NotSearching /**< The not searching */
	};
}
#endif