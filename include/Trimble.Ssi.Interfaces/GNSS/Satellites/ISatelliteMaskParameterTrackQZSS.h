#ifndef ISATELLITEMASKPARAMETERTRACKQZSS_H_
#define ISATELLITEMASKPARAMETERTRACKQZSS_H_

#include "ISatelliteMaskParameter.h"

namespace SSI
{
	/**
	* Represents satellite mask track BeiDou parameter.
	*/
	class ISatelliteMaskParameterTrackQZSS: public ISatelliteMaskParameter
	{
	public:
		virtual ~ISatelliteMaskParameterTrackQZSS();

		/**
		* Gets a value indicating whether QZSS is tracked.
		* @return true if QZSS tracked;  otherwise, false.
		*/
		virtual bool getTrackQZSS() = 0;

		/**
		* Sets a value indicating whether QZSS should be tracked.
		* @param trackQZSS  true if QZSS should be tracked; otherwise, false.
		*/
		virtual void setTrackQZSS(bool trackQZSS) = 0;
	};
}
#endif