#ifndef ISATELLITEMASKPARAMETERTRACKL2C_H_
#define ISATELLITEMASKPARAMETERTRACKL2C_H_

#include "ISatelliteMaskParameter.h"

namespace SSI
{
	/**
	* Represents satellite mask track L2C parameter.
	*/
	class ISatelliteMaskParameterTrackL2C: public ISatelliteMaskParameter
	{
	public:
		virtual ~ISatelliteMaskParameterTrackL2C();

		/**
		* Gets a value indicating whether L2C is tracked.
		* @return true if L2C is tracked; otherwise, false.
		*/
		virtual bool getTrackL2C() = 0;

		/**
		* Sets a value indicating whether L2C should be tracked.
		* @param true if L2C should be tracked; otherwise, false.
		*/
		virtual void setTrackL2C(bool trackL2C) = 0;
	};
}
#endif