#ifndef IVIDEOSTREAMINGUPDATELISTENER_H_
#define IVIDEOSTREAMINGUPDATELISTENER_H_

#include "VideoStreamingUpdateEvent.h"

namespace SSI
{
	/**
	* listens for video streaming updates.
	*/
	class IVideoStreamingUpdateListener
	{
	public:
		virtual ~IVideoStreamingUpdateListener();
		/**
		* process the occurred event
		* @param the event
		*/
		virtual void videoStreamigUpdate(const VideoStreamingUpdateEvent& event) = 0;
	};
}
#endif
