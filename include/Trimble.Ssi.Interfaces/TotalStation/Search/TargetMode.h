#ifndef TARGETMODE_H_
#define TARGETMODE_H_

namespace SSI
{
	/**
	* Represents the view of the multi target search.
	*/
	enum TargetMode
	{
		TM_Prism, 		/**< Do the search optimized for prims. */
		TM_Cateye, 		/**< Do the search optimized for cateyes. */
		TM_Foil, 		/**< Do the search optimized for foil stickers. */
	};
}
#endif