#ifndef POSITIONINGOBSERVATIONEVENTARGS_H_
#define POSITIONINGOBSERVATIONEVENTARGS_H_

#include  "GNSSObservationContainer.h"

namespace SSI
{
	/*
	* Provides data for the Positioning Update.
	*/
	class PositioningObservationUpdate
	{
	public:
		/*
		* Initializes a new instance of the PositioningObservationUpdate
		*/
		PositioningObservationUpdate(GNSSObservationContainer& observations);

		/*Gets the observations.
		* @return GNSSObservationContainer&
		*/
		const GNSSObservationContainer& getObservations() const;
	private:
		PositioningObservationUpdate();
		PositioningObservationUpdate(const PositioningObservationUpdate& copyMe);
		PositioningObservationUpdate& operator=(const PositioningObservationUpdate&);
		GNSSObservationContainer _observations;
	};
}
#endif