#ifndef ISSIPRESSURE_H_
#define ISSIPRESSURE_H_

#include "ISsiInterface.h"

namespace SSI
{
	/**
	* Provides access to the pressure sensor of an instrument.
	* For a brief description of features and usage of various ISsiInterface see [Guides: Interfaces](@ref Guides_Interfaces)
	*/
	class ISsiPressure : public ISsiInterface
	{
	public:
		virtual ~ISsiPressure();
	
		/**
		* get the pressure.
		* @return the pressure
		*/
		virtual double getPressure() const = 0;
	};
}
#endif