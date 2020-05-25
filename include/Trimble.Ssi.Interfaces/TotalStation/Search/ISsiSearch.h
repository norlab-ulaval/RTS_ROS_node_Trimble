#ifndef ISSISEARCH_H_
#define ISSISEARCH_H_

#include "ISsiInterface.h"
#include "ISearchStateChangedListener.h"
#include "../Targets/ITarget.h"
#include "ISearchParameter.h"
#include <vector>

namespace SSI
{
	/**
	* Provides members to access search functions of an instrument.
	* For a brief description of features and usage of various ISsiInterface see [Guides: Interfaces](@ref Guides_Interfaces)
	* @see ISsiTargets
	*/
	class ISsiSearch : public ISsiInterface
	{
	public:
		virtual ~ISsiSearch();
		
		/**
		* register a listener.
		* @param ISearchStateChangedListener the listener
		*/
		virtual void addSearchStateChangedListener(ISearchStateChangedListener& listener) = 0;
		
		/**
		* unsubscribe a listener.
		* @param ISearchStateChangedListener the listener
		*/
		virtual void removeSearchStateChangedListener(ISearchStateChangedListener& listener) = 0;
		
		/**
		* Gets the state of the search.
		* @return The state of the search.
		*/
		virtual SearchState getSearchState() const = 0;
		
		/**
		* Returns an enumeration all available parameter types.
		* Use CreateParameter to create an ISearchParameter by it's type for use with Search.
		* @return An enumeration of available parameter types.
		*/
		virtual std::vector<SearchParameterType> listSupportedParameterTypes() const = 0;
		
		/**
		* is the parameter type supported.
		* @param SearchParameterType to check
		* @return true if it is otherwise false
		*/
		virtual bool isParameterSupported(SearchParameterType searchParameterType) const = 0;

		/**
		* Creates the parameter associated with the specified parameterType.
		* @param SearchParameterType Type of the parameter.
		* @return An instance of the ISearchParameter interface, associated with the specified SearchParameterType.
		*/
		virtual ISearchParameter* createParameter(SearchParameterType searchParameterType) = 0;

		/**
		* Determines whether the specified target is supported for starting search.
		* @param ITarget The target.
		* @returns <c>true</c> if the target is supported; otherwise, <c>false</c>.
		*/
		virtual bool isTargetSupported(ITarget& target) const = 0;

		/**
		* Starts searching for a target in a window defined by the given parameter.
		* The operation is not supported for Direct Reflex targets.
		* Prism targets must implement the IPrismAdvancedTarget interface.
		* The IPrismAdvancedTarget.WorkingMode must not be WorkingMode.Manual.
		* For further limitations based on the instruments capabilities check IsTargetSupported.
		* @param ISearchParameter The search parameter.
		*/
		virtual void search(ISearchParameter& searchParameter) = 0;

		/**
		* Cancels the pending search operation.
		* Cancellation of a search operation, which has not been started yet does not affect the state of the ISsiSearch instance.
		*/
		virtual void cancelSearch() = 0;
	};
}
#endif