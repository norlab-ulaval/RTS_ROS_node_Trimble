#ifndef ISEARCHPARAMETERVIEW_H_
#define ISEARCHPARAMETERVIEW_H_

#include "ISearchParameter.h"
#include "SearchView.h"

namespace SSI
{
	/**
	* Represents a search parameter for defining the view of a multi target search.
	*/
	class ISearchParameterView : public ISearchParameter
	{
	public:
		virtual ~ISearchParameterView();

		/**
		* Gets the search view.
		* @return the multi target search view
		*/
		virtual SearchView getSearchView() const = 0;
	
		/**
		* Sets the search view.
		* @param searchView The search view.
		*/
		virtual void setSearchView(SearchView searchView) = 0;
	};
}
#endif