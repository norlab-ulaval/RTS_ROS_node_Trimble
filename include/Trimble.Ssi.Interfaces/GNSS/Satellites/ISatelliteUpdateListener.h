#ifndef ISATELLITEUPDATELISTENER_H_
#define ISATELLITEUPDATELISTENER_H_

#include "SatelliteUpdate.h"

namespace SSI
{
	/**
	* Listens for changed position.
	*/
	class ISatelliteUpdateListener
	{
	public:
		virtual ~ISatelliteUpdateListener();

		/**
		* receives the event message when changes occur.
		* @param satelliteUpdate that occurred
		*/
		virtual void onSatelliteUpdate(const SatelliteUpdate& satelliteUpdate) = 0;
	};
}
#endif