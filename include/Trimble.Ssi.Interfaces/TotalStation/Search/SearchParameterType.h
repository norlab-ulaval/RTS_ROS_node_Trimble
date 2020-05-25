#ifndef SEARCHPARAMETERTYPE_H_
#define SEARCHPARAMETERTYPE_H_

namespace SSI
{
	/**
	* Represents the parameter for a prism search.
	* To get an enumeration of supported SearchParameterType values, use ISsiSearch.ListSupportedParameterTypes
	* Use ISsiSearch.CreateParameter to create a specific search parameter based on the SearchParameterType
	* @see ISsiSearch
	*/
	enum SearchParameterType
	{
		SPT_RelativeAngles,		/** Type of a search parameter which is defined by relative angles. */
		SPT_HorizontalAngle,	/** Type of a search parameter which is defined by horizontal angle. */
		SPT_AbsoluteAngles,		/** Type of a search parameter which is defined by absolute angles. */
		SPT_SearchMode,			/** Type of a search mode parameter for a multi target search. */
		SPT_SearchView,			/** Type of a search view parameter for a multi target search. */
		SPT_TargetMode 			/** Type of a target mode parameter for a multi target search. */
	};
}
#endif