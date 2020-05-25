#ifndef ISATELLITEMASKPARAMETERTRACKL5_H_
#define ISATELLITEMASKPARAMETERTRACKL5_H_

#include "ISatelliteMaskParameter.h"

namespace SSI
{
	/**
	* Represents satellite mask track L5 parameter.
	*/
	class ISatelliteMaskParameterTrackL5: public ISatelliteMaskParameter
	{
	public:
		virtual ~ISatelliteMaskParameterTrackL5();

		/**
		* Gets or sets a value indicating whether L5 is tracked.
		* @return true if L5 is tracked; otherwise, false.
		*/
		virtual bool getTrackL5() = 0;

		/**
		* Sets a value indicating whether L5 should be tracked.
		* @param true if L5 should be tracked; otherwise, false.
		*/
		virtual void setTrackL5(bool trackL5) = 0;
	};
}
#endif