#ifndef PANORAMASTATEUPDATEEVENT_H
#define PANORAMASTATEUPDATEEVENT_H
#include "PanoramaState.h"

namespace SSI
{
class PanoramaStateUpdateEvent
{
public:
	PanoramaStateUpdateEvent(PanoramaState panoramaState);
	~PanoramaStateUpdateEvent();
	PanoramaState getState();
private:
	PanoramaState _state;
};
}

#endif        //  #ifndef PANORAMASTATEUPDATEEVENT_H
