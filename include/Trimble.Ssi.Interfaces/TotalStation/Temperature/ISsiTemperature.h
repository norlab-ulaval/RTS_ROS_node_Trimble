#ifndef ISSITEMPERATURE_H_
#define ISSITEMPERATURE_H_

#include "ISsiInterface.h"

namespace SSI
{
	/**
	* Provides access to the temperature sensor of an instrument.
	* For a brief description of features and usage of various ISsiInterface see [Guides: Interfaces](@ref Guides_Interfaces)
	*/
	class ISsiTemperature : public ISsiInterface
	{
	public:
		virtual ~ISsiTemperature();
	
		/**
		* get the temperature.
		* @return the temperature
		*/
		virtual double getTemperature() const = 0;
	};
}
#endif