#ifndef IREFERENCESTATIONLISTENER_H_
#define IREFERENCESTATIONLISTENER_H_

#include "ReferenceStationUpdate.h"

namespace SSI
{
	/**
	* Listens for changed reference station.
	*/
	class IReferenceStationListener
	{
	public:
		virtual ~IReferenceStationListener();

		/**
		* receives the event message when changes occur.
		* @param ReferenceStationUpdate that occurred
		*/
		virtual void onRefereceStationUpdate(const ReferenceStationUpdate& referenceStationUpdate) = 0;
	};
}
#endif