#ifndef SATELLITEUPDATE_H_
#define SATELLITEUPDATE_H_

#include "SatelliteContainer.h"

namespace SSI
{
	/**
	* Provides data for the @see ISatelliteUpdateListener::onSatelliteUpdate event.
	* @see ISsiSatellites.SatellitesUpdate
	* @see ISsiSatellites
	*/
	class SatelliteUpdate
	{
	public:
		/**
		* Initializes a new instance of the @see SatelliteUpdateEventArgs class.
		* @param container The container.
		*/
		SatelliteUpdate(SatelliteContainer* container);

		virtual ~SatelliteUpdate();

		/**
		* Gets the satellite container.
		* @return The satellite container.
		*/
		virtual SatelliteContainer* getSatelliteContainer() const;

	private:
		SatelliteContainer* _container;

		SatelliteUpdate();
		SatelliteUpdate(const SatelliteUpdate& copyMe);
		SatelliteUpdate& operator=(const SatelliteUpdate&);
	};
}
#endif