#ifndef SEARCHPROGRESSLISTENER_H_
#define SEARCHPROGRESSLISTENER_H_

#include "SearchProgressEvent.h"

namespace SSI
{
	/**
	* listens for search progress changes.
	*/
	class ISearchProgressListener
	{
	public:
		virtual ~ISearchProgressListener();
	
		/**
		* process the occurred event
		* @param the event
		*/
		virtual void searchProgressChanged(const SearchProgressEvent& event) = 0;
	};
}
#endif