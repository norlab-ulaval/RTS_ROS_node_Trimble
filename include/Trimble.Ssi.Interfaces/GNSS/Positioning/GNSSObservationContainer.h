#ifndef GNSSOBSERVATIONCONTAINER_H_
#define GNSSOBSERVATIONCONTAINER_H_

#include "IGNSSObservation.h"
#include <vector>

namespace SSI
{
	/**
	* Provides access to observations that were generated during measurement or tracking.
	* The operation ISsiMeasurement::Measure as well as the TrackingObservationsEventArgs returns an instance of the GNSSObservationContainer.
	* @see ISsiPositioning
	*/
	class GNSSObservationContainer
	{
	public:
		/**
		* constructor.
		* @param std::vector<IGNSSObservation*> the observations
		*/
		GNSSObservationContainer(std::vector<IGNSSObservation*>& observations);
		GNSSObservationContainer();
		virtual ~GNSSObservationContainer();

		/**
		* get the observations.
		* @return the observations
		*/
		std::vector<IGNSSObservation*> getObservations() const;

		GNSSObservationContainer(const GNSSObservationContainer& copyMe);
		GNSSObservationContainer& operator=(const GNSSObservationContainer&);
	private:
		std::vector<IGNSSObservation*> _observations; /** observation list */
	};
}
#endif