#ifndef ISATELLITEMASKPARAMETERTRACKGALILEO_H_
#define ISATELLITEMASKPARAMETERTRACKGALILEO_H_

#include "ISatelliteMaskParameter.h"

namespace SSI
{
	/**
	* Represents satellite mask track Galileo parameter.
	*/
	class ISatelliteMaskParameterTrackGalileo: public ISatelliteMaskParameter
	{
	public:
		virtual ~ISatelliteMaskParameterTrackGalileo();

		/**
		* Gets a value indicating whether track Galileo is tracked.
		* @return true  if Galileo is tracked; otherwise, false.
		*
		*/
		virtual bool getTrackGalileo() = 0;

		/**
		* Sets a value indicating whether track Galileo should be tracked.
		* @param trackGalileo true  if Galileo should be tracked; otherwise, false.
		*
		*/
		virtual void setTrackGalileo(bool trackGalileo) = 0;
	};
}
#endif