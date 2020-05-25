#ifndef ISATELLITEMASKPARAMETERMINELEVATION_H_
#define ISATELLITEMASKPARAMETERMINELEVATION_H_

#include "ISatelliteMaskParameter.h"

namespace SSI
{
	/**
	* Represents satellite min elevation mask parameter.
	*/
	class ISatelliteMaskParameterMinElevation: public ISatelliteMaskParameter
	{
	public:

		virtual ~ISatelliteMaskParameterMinElevation();

		/**
		* Gets the min elevation minimum.
		* @return The min elevation minimum.
		*/
		virtual double getMinElevationMinimum() = 0;

		/**
		* Gets the min elevation maximum.
		* @return The min elevation maximum.
		*/
		virtual double getMinElevationMaximum() = 0;

		/**
		* Gets the min elevation.
		* @return  The min elevation.
		*/
		virtual double getMinElevation() = 0;

		/**
		* Sets the min elevation.
		* @param minElevation  The min elevation.
		*/
		virtual void setMinElevation(const double& minElevation) = 0;
	};
}
#endif