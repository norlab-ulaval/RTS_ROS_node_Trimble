#ifndef IPANORAMAIMAGELISTENER_H
#define IPANORAMAIMAGELISTENER_H
#include "PanoramaUpdateEvent.h"

namespace SSI
{
class IPanoramaImageListener
{
public :
	IPanoramaImageListener();
	virtual ~IPanoramaImageListener();
	
	virtual void onPanoramaUpdate(const PanoramaUpdateEvent& panoramaUpdate) = 0;
};
}
#endif        //  #ifndef IPANORAMAIMAGELISTENER_H
