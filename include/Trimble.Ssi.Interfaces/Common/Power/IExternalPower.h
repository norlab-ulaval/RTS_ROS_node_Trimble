#ifndef IEXTERNALPOWER_H_
#define IEXTERNALPOWER_H_

#include "IPowerSource.h"
#include "ExternalPowerState.h"

namespace SSI
{
	/**
	* Represents an external power source.
	* @see ISsiPower
	*/
	class IExternalPower : public IPowerSource
	{
	public:
		virtual ~IExternalPower();

		/**
		* Gets the status of the external power source.
		* @return status of the external power source.
		*/
		virtual ExternalPowerState getExternalPowerState() const = 0;
	};
}
#endif