#ifndef IPOWERSOURCE_H_
#define IPOWERSOURCE_H_

#include "PowerSourceType.h"

namespace SSI
{
	/**
	* Represents a basic power source.
	* @see ISsiPower
	*/
	class IPowerSource
	{
	public:
		virtual ~IPowerSource();

		/**
		* get the power source type.
		* @return the power source type.
		*/
		virtual PowerSourceType getPowerSourceType() const = 0;
	};
}
#endif
