#ifndef ISATELLITEMASKPARAMETERTRACKGPS_H_
#define ISATELLITEMASKPARAMETERTRACKGPS_H_

#include "ISatelliteMaskParameter.h"

namespace SSI
{
	/**
	* Represents satellite mask track GPS parameter.
	*/
	class ISatelliteMaskParameterTrackGPS : public ISatelliteMaskParameter
	{
	public:
		virtual ~ISatelliteMaskParameterTrackGPS();

		/**
		* Gets a value indicating whether GPS is tracked.
		* @return true  if GPS is tracked; otherwise, false.
		*
		*/
		virtual bool getTrackGPS() = 0;

		/**
		* Sets a value indicating whether GPS should be tracked.
		* @param trackGPS true if GPS should be tracked; otherwise, false.
		*/
		virtual void setTrackGPS(bool trackGPS) = 0;
	};
}
#endif