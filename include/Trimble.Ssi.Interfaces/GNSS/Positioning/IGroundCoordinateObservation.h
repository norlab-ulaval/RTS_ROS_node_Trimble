#ifndef IGROUNDCOORDINATEOBSERVATION_H_
#define IGROUNDCOORDINATEOBSERVATION_H_

#include "ICoordinateObservation.h"

namespace SSI
{
	/*
	* The coordinate at the ground point
	*/
	class IGroundCoordinateObservation : public ICoordinateObservation
	{
	public:
		virtual ~IGroundCoordinateObservation();
	};
}
#endif