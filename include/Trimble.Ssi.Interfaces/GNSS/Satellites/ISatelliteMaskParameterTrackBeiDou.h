#ifndef ISATELLITEMASKPARAMETERTRACKBEIDOU_H_
#define ISATELLITEMASKPARAMETERTRACKBEIDOU_H_

#include "ISatelliteMaskParameter.h"

namespace SSI
{
	/**
	* Represents satellite mask track BeiDou parameter.
	*/
	class ISatelliteMaskParameterTrackBeiDou: public ISatelliteMaskParameter
	{
	public:
		virtual ~ISatelliteMaskParameterTrackBeiDou();

		/**
		* Gets or sets a value indicating whether BeiDou is tracked.
		* @return true if BeiDou is tracked; otherwise, false.
		*/
		virtual bool getTrackBeiDou() = 0;

		/**
		* Sets a value indicating whether BeiDou should be tracked.
		* @param true if BeiDou should be tracked; otherwise, false.
		*/
		virtual void setTrackBeiDou(bool trackBeiDou) = 0;
	};
}
#endif