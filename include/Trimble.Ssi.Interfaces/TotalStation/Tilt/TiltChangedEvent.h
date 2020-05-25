#ifndef TILTCHANGEDEVENT_H_
#define TILTCHANGEDEVENT_H_

#include "LevelTilt.h"

namespace SSI
{
	/**
	* Provides data for the ISsiTilt::TiltChanged event.
	* @see ISsiTilt::TiltChanged
	* @see ISsiTilt
	*/
	class TiltChangedEvent
	{
	public:
		/**
		* Initializes a new instance of the TiltChangedEventArgs class.
		* @param LevelTilt the tilt level
		*/
		TiltChangedEvent(const LevelTilt& tilt);
		virtual ~TiltChangedEvent();

		/**
		* get the tilt level
		* @return the tilt level
		*/
		LevelTilt getTilt() const;
		TiltChangedEvent(const TiltChangedEvent& copyMe);
	private:
		TiltChangedEvent();
		TiltChangedEvent& operator=(const TiltChangedEvent&);
		LevelTilt _tilt; /** the tilt level */
	};
}
#endif