#ifndef ICOORDINATEOBSERVATION_H_
#define ICOORDINATEOBSERVATION_H_

#include "Coordinates.h"
#include "IGNSSObservation.h"

namespace SSI
{
	/*
	* Represents a coordinate observation.
	* @remark The coordinates are not corrected by any means. Corrections like antenna height and antenna phase center has to be applied manually.
	*/
	class ICoordinateObservation: public IGNSSObservation
	{
	public:
	
		/* Gets the coordinates.
		* @return Coordinates
		*/
		virtual Coordinates getCoordinates()=0;

		virtual ~ICoordinateObservation();
	};
}
#endif