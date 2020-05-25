#ifndef ISATELLITEMASKPARAMETER_H_
#define ISATELLITEMASKPARAMETER_H_

#include "SatelliteMaskParameterType.h"

namespace SSI
{
	/**
	* Represents satellite mask parameter.
	*/
	class ISatelliteMaskParameter
	{
	public:
		virtual ~ISatelliteMaskParameter();

		/**
		* Gets the type.
		* @return The type.
		*/
		virtual SatelliteMaskParameterType getType() = 0;
	};
}
#endif