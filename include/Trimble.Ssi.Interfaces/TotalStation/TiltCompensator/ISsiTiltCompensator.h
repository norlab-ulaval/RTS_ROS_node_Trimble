#ifndef ISSITILTCOMPENSATOR_H_
#define ISSITILTCOMPENSATOR_H_

#include "ISsiInterface.h"

namespace SSI
{
	/**
	* Provides access to the tilt compensator of an instrument.
	* For a brief description of features and usage of various ISsiInterface see [Guides: Interfaces](@ref Guides_Interfaces)
	*/
	class ISsiTiltCompensator : public ISsiInterface
	{
	public:
		virtual ~ISsiTiltCompensator();

		/*
		* Check if the tilt compensator is enabled.
		* When the compensator is enabled through setEnabled but the tilt is out of range it will not be applied to observations.
		* IsCompensatorEnabled still returns true then.
		* @return true if the tilt compensator is enabled; otherwise false
		*/
		virtual bool getEnabled() const = 0;

		/**
		* Enables/disables the tilt compensator.
		* Enabling the compensator will not necessarily activate it, e.g. when the tilt is out of range.
		* @param bool for enable set true; otherwise false
		*/
		virtual void setEnabled(bool enabled) = 0;
	};
}
#endif