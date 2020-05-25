#ifndef ISTREAMINGSTATECHANGEDLISTENER_H_
#define ISTREAMINGSTATECHANGEDLISTENER_H_

#include "StreamingStateChangedEvent.h"

namespace SSI
{
	/**
	* listens for streaming state changes.
	*/
	class IStreamingStateChangedListener
	{
	public:
		virtual ~IStreamingStateChangedListener();
		/**
		* process the occurred event
		* @param the event
		*/
		virtual void streamingStateChanged(const StreamingStateChangedEvent& event) = 0;
	};
}
#endif
