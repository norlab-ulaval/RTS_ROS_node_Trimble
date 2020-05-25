#ifndef ISSIMULTITARGETSEARCH_H_
#define ISSIMULTITARGETSEARCH_H_

#include "ISsiInterface.h"
#include "SearchState.h"
#include "SearchParameterType.h"
#include "ISearchParameter.h"
#include "Observations/ISearchObservationsListener.h"
#include "ISearchStateChangedListener.h"
#include "Search/ISearchProgressListener.h"

#include <vector>

namespace SSI
{
	/**
	* Provides members to access multi target search functions of an instrument.
	* For a brief description of features and usage of various <see cref="ISsiInterface"/> see [Guides: Interfaces](@ref Guides_Interfaces).
	* <seealso cref="ISsiTargets"/>
	*/
	class ISsiMultiTargetSearch : public ISsiInterface
	{
	public:
		virtual ~ISsiMultiTargetSearch();
		
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
		* register a listener.
		* @param ISearchObservationsListener the listener
		*/
		virtual void addSearchObservationsListener(ISearchObservationsListener& listener) = 0;
		
		/**
		* unsubscribe a listener.
		* @param ISearchObservationsListener the listener
		*/
		virtual void removeSearchObservationsListener(ISearchObservationsListener& listener) = 0;

		/**
		* register a listener for listening
		* @param listener ISearchProgressListener to listen
		*/
		virtual void addSearchProgressListener(ISearchProgressListener& listener) = 0;
		
		/**
		* unsubscribe a listener from listening
		* @param listener ISearchProgressListener to listen
		*/
		virtual void removeSearchProgressListener(ISearchProgressListener& listener) = 0;

		/**
		* Gets the state of the search.
		* @return The state of the search.
		*/
		virtual SearchState getSearchState() const = 0;

		/**
		* Returns an enumeration all available parameter types.
		* Use <see cref="createParameter"/> to create an <see cref="ISearchParameter"/> by it's type for use with <see cref="Search"/>.
		* @return An list of available parameter types.
		*/
		virtual std::vector<SearchParameterType> listSupportedSearchParameterTypes() const = 0;

		/**
		* Determines whether the specified type is supported.
		* @param type The type.
		* @return true if it is, otherwise false
		*/
		virtual bool isSearchParameterSupported(SearchParameterType type) const = 0;

		/**
		* Creates the parameter associated with the specified <paramref name="parameterType"/>.
		* @param parameterType Type of the parameter.
		* @return An instance of the <see cref="ISearchParameter"/> interface, associated with the specified <paramref name="parameterType"/>.
		*/
		virtual ISearchParameter* createParameter(SearchParameterType parameterType) = 0;

		/**
		* Starts searching for a target in a window defined by the given <paramref name="parameter"/>.
		* The operation is not supported for Direct Reflex targets.
		* Prism targets must implement the <see cref="IPrismAdvancedTarget"/> interface.
		* The <see cref="IPrismAdvancedTarget.WorkingMode"/> must not be <see cref="WorkingMode.Manual"/>.
		* For further limitations based on the instruments capabilities check <see cref="isSupported"/>.
		* @param parameter The search parameters.
		*/
		virtual void search(std::vector<ISearchParameter*> parameter) = 0;

		/**
		* Cancels the pending search operation.
		* Cancellation of a search operation, which has not been started yet does not affect the state of the <see cref="ISsiSearch"/> instance.
		*/
		virtual void cancelSearch() = 0;
	};
}
#endif