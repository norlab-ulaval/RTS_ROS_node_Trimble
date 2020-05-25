#ifndef ISEARCHPARAMETER_H_
#define ISEARCHPARAMETER_H_

#include"SearchParameterType.h"

namespace SSI
{
	/**
	* Represents a basic search parameter.
	* Use ISsiSearch.CreateParameter to create an ISearchParameter for use with ISsiSearch.Search.
	* @see ISsiSearch
	*/
	class ISearchParameter
	{
	public:
		virtual ~ISearchParameter();
	
		/**
		* Gets the type of this search parameter.
		* @return the search parameter type
		*/
		virtual SearchParameterType getSearchParameterType() const = 0;
	};
}
#endif