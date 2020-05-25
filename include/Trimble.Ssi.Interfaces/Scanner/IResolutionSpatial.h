#ifndef IRESOLUTIONSPATIAL_H
#define IRESOLUTIONSPATIAL_H
#include "IScanResolution.h"

namespace SSI
{
	/**
	* Any scan resolution defined by a distance.
	* @see Trimble.Ssi.Interfaces.Scanner.IScanResolution
	*/
	class IResolutionSpatial : public IScanResolution
	{
	public:

	virtual ~IResolutionSpatial();

	/**
	* Gets the spatial resolution in meter.
	* @return
	* The interval in meter.
	*/
	virtual double getIntervalInMeter() = 0;

	/**
	* Sets the spatial resolution in meter.
	* @param intervalInMeter
	* The interval in meter.
	*/
	virtual void setIntervalInMeter(double intervalInMeter) = 0;

	/**
	* Gets the minimum spatial resolution.
	* @return
	* The resolution minimum.
	*
	*/
	virtual double getResolutionMin() = 0;

	/**
	* Gets the maximum spatial resolution.
	* @return
	* The resolution maximum.
	*
	*/
	virtual double getResolutionMax() = 0;
	};
}

#endif // IRESOLUTIONSPATIAL_H
