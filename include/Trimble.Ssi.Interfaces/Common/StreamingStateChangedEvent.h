#ifndef STREAMINGSTATECHANGEDEVENT_H_
#define STREAMINGSTATECHANGEDEVENT_H_

#include "StreamingState.h"

namespace SSI
{
	/**
	*
	*/
	class StreamingStateChangedEvent
	{
	public:
		virtual ~StreamingStateChangedEvent();

		/**
		* Initializes a new instance of the StreamingStateChangedEvent class.
		* @param streamingState the new streaming state.
		*/
		StreamingStateChangedEvent(StreamingState streamingState);

		/**
		* Gets the streaming state.
		* @return The streaming state.
		*/
		StreamingState getStreamingState() const;
	private:
		StreamingStateChangedEvent();
		StreamingStateChangedEvent(const StreamingStateChangedEvent& copyMe);
		StreamingStateChangedEvent& operator=(const StreamingStateChangedEvent&);
		StreamingState _streamingState;
	};
}
#endif