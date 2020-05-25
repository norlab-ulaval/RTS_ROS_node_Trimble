#ifndef SEARCHMODE_H_
#define SEARCHMODE_H_

namespace SSI
{
	/**
	* Represents the multi target search mode.
	*/
	enum SearchMode
	{
		SM_TargetByTarget,	/**< Do the search target by target. */
		SM_CoarseAndFine,	/**< Do first a complete coarse search and after that a fine search target by target. */
		SM_Download,		/**< Download the target search data. */
	};
}
#endif