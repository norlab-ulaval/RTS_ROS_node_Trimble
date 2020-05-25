#ifndef REFERENCESTATIONUPDATE_H_
#define REFERENCESTATIONUPDATE_H_

#include "ReferenceStation.h"

namespace SSI
{
	/*
	* Provides data for the  ReferenceStation Update event
	*/
	class ReferenceStationUpdate
	{
	public:
		/*
		* Initializes a new instance of the ReferenceStationUpdate
		* @param ReferenceStation
		*/
		ReferenceStationUpdate(ReferenceStation& referenceStation);

		/*
		* Gets the reference station.
		* @return ReferenceStation
		*/
		ReferenceStation getReferenceStation() const;
	private:
		ReferenceStation _referenceStation;
	};
}
#endif