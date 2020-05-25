#ifndef IPANORAMASTATELISTENER_H
#define IPANORAMASTATELISTENER_H
#include "PanoramaStateUpdateEvent.h"

namespace SSI
{
class IPanoramaStateListener
{
public :
	IPanoramaStateListener();
	virtual ~IPanoramaStateListener();
	
	virtual void onPanoramaStateChange(const PanoramaStateUpdateEvent& panoramaStateUpdate) = 0;
};
}
#endif        //  #ifndef IPANORAMASTATELISTENER_H
