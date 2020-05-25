#ifndef ISEARCHPARAMETERMODE_H_
#define ISEARCHPARAMETERMODE_H_

#include "ISearchParameter.h"
#include "SearchMode.h"

namespace SSI
{
	/**
	* Represents a search parameter for defining the search mode of the multi target search.
	*/
	class ISearchParameterMode : public ISearchParameter
	{
	public:
		virtual ~ISearchParameterMode();
		
		/**
		* Gets the search mode.
		* @return The search mode.
		*/
		virtual SearchMode getSearchMode() const = 0;
		
		/**
		* Sets the search mode.
		* @param searchMode The search mode.
		*/
		virtual void setSearchMode(SearchMode searchMode) = 0;
	};
}
#endif