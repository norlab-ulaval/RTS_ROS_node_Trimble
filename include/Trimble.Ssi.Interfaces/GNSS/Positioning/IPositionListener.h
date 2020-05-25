#ifndef IIPOSITIONLISTENER_H_
#define IIPOSITIONLISTENER_H_

#include "PositioningObservationUpdate.h"

namespace SSI
{
	/**
	* Listens for changed position.
	*/
	class IPositionListener
	{
	public:
		virtual ~IPositionListener();

		/**
		* receives the event message when changes occur.
		* @param PositioningObservationUpdate that occurred
		*/
		virtual void onPositionUpdate(const PositioningObservationUpdate& positioningObservationUpdate) = 0;
	};
}
#endif