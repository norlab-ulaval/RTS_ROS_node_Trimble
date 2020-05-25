#ifndef ISTATUSLIGHTCONFIGURATION_H
#define ISTATUSLIGHTCONFIGURATION_H

#include "StatusLightState.h"
#include "StatusLightType.h"
#include <vector>

namespace SSI
{
	/**
	* Represents the configuration of the status light.
	*/
	class IStatusLightConfiguration
	{
	public:
		virtual ~IStatusLightConfiguration();

		/**
		* Gets the status light type.
		*/
		virtual StatusLightType getLightType() const = 0;

		/**
		* Return an enumeration of all supported status light states.
		* @return An enumeration of all supported status light states.
		*/
		virtual std::vector<StatusLightState> listSupportedStatusLightStates() const = 0;

		/**
		* Determines whether the specified status light state is supported.
		* @param state The state.
		* @return bool
		*/
		virtual bool isSupported(StatusLightState state) const = 0;

		/**
		* Gets the state of the LED.
		* @return StatusLightState
		*/
		virtual StatusLightState getLightState() const = 0;

		/**
		* Sets the state of the LED.
		* @param state the StatusLightState
		*/
		virtual void setLightState(StatusLightState state) = 0;

		/**
		* Gets the brightness of the LED.
		* @return int should be between 0 and 100
		*/
		virtual int getBrightness() const = 0;

		/**
		* Sets the brightness of the LED.
		* @param value should be between 0 and 100
		*/
		virtual void setBrightness(int value) = 0;
	};
}
#endif