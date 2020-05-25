#ifndef IPANORAMASTATUSLISTENER_H
#define IPANORAMASTATUSLISTENER_H
#include "PanoramaStatusUpdateEvent.h"

namespace SSI
{
	class IPanoramaStatusListener
	{
	public:
		IPanoramaStatusListener();
		virtual ~IPanoramaStatusListener();

		virtual void onPanoramaStatusChange(const PanoramaStatusUpdateEvent& panoramaStatusUpdate) = 0;
	};
}
#endif        //  #ifndef IPANORAMASTATUSLISTENER_H
