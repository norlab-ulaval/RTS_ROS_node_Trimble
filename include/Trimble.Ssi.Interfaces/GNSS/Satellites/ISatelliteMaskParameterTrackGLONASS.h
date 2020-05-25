#ifndef ISATELLITEMASKPARAMETERTRACKGLONASS_H_
#define ISATELLITEMASKPARAMETERTRACKGLONASS_H_

#include "ISatelliteMaskParameter.h"

namespace SSI
{
	/**
	* Represents satellite mask track GLONASS parameter.
	*/
	class ISatelliteMaskParameterTrackGLONASS: public ISatelliteMaskParameter
	{
	public:
		virtual ~ISatelliteMaskParameterTrackGLONASS();

		/**
		* Gets a value indicating whether GLONASS is tracked.
		* @return true  if GLONASS is tracked; otherwise, false.
		*/
		virtual bool getTrackGLONASS() = 0;

		/**
		* Sets a value indicating whether GLONASS should be tracked.
		* @param trackGLONASS true if GLONASS should be tracked; otherwise, false.
		*/
		virtual void setTrackGLONASS(bool trackGLONASS) = 0;
	};
}
#endif