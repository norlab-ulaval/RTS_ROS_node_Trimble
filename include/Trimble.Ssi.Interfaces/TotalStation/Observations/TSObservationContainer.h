#ifndef OBSERVATIONCONTAINER_H_
#define OBSERVATIONCONTAINER_H_

#include "ITSObservation.h"
#include <vector>

namespace SSI
{
	/**
	* Provides access to observations that were generated during measurement or tracking.
	* The operation ISsiMeasurement::Measure as well as the TrackingObservationsEventArgs returns an instance of the ObservationContainer.
	* @see ISsiMeasurement
	* @see ISsiTracking
	*/
	class TSObservationContainer
	{
	public:
		/**
		* constructor.
		* @param std::vector<ITSObservation*> the observations
		*/
		TSObservationContainer(std::vector<ITSObservation*>& observations);
		TSObservationContainer();
		virtual ~TSObservationContainer();
		
		/**
		* get the observations.
		* @return the observations
		*/
		std::vector<ITSObservation*> getObservations() const;

		TSObservationContainer(const TSObservationContainer& copyMe);
		TSObservationContainer& operator=(const TSObservationContainer&);
	private:
		std::vector<ITSObservation*> _observations; /** observation list */
	};
}
#endif