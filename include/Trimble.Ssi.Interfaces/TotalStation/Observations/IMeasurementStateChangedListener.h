#ifndef MEASUREMENTSTATECHANGEDLISTENER_H_
#define MEASUREMENTSTATECHANGEDLISTENER_H_

#include "MeasurementStateChangedEvent.h"

namespace SSI
{
	/**
	* listens for measurement state changes.
	*/
	class IMeasurementStateChangedListener
	{
	public:
		virtual ~IMeasurementStateChangedListener();
	
		/**
		* process the occurred event
		* @param the event
		*/
		virtual void measurementStateChanged(const MeasurementStateChangedEvent& event) = 0;
	};
}
#endif