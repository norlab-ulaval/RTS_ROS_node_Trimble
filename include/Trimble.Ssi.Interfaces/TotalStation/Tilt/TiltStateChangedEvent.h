#ifndef TILTSTATECHANGEDEVENT_H_
#define TILTSTATECHANGEDEVENT_H_

#include "TiltState.h"

namespace SSI
{
	/**
	* Provides data for the ISsiTilt::TiltStateChanged event.
	* @see ISsiTilt::TiltStateChanged
	* @see ISsiTilt
	*/
	class TiltStateChangedEvent
	{
	public:
		/**
		* Initializes a new instance of the TiltStateChangedEventArgs class.
		* @param TiltState the tilt state
		*/
		TiltStateChangedEvent(TiltState state);
		virtual ~TiltStateChangedEvent();
	
		/**
		* get the tilt state.
		* @return the tilt state
		*/
		TiltState getTiltState() const;
	private:
		TiltStateChangedEvent();
		TiltStateChangedEvent(const TiltStateChangedEvent& copyMe);
		TiltStateChangedEvent& operator=(const TiltStateChangedEvent&);
		TiltState _state; /** the tilt state */
	};
}
#endif