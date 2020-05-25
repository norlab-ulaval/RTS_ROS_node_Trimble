#ifndef IRADIOCONFIGURATIONAIRLINKSPEED_H_
#define IRADIOCONFIGURATIONAIRLINKSPEED_H_

#include <vector>
#include "IRadioConfigurationGnss.h"

namespace SSI
{
	/**
	* The radio parameter for changing the air link speed of the radio
	*/
	class IRadioConfigurationAirLinkSpeed : public virtual IRadioConfigurationGnss
	{
	public:
		virtual ~IRadioConfigurationAirLinkSpeed();

		/**
		* Returns an enumeration of available <see cref="speed"/>.
		* Please be aware, that the underlying enumeration later may contain values, which are not known now.
		* @return An enumeration of available <see cref="speed"/> objects.
		*/
		virtual std::vector<int> listSupportedSpeedRates() const = 0;

		/**
		* Is Speed rate supported.
		* @param speed to check
		* @return true if it is otherwise false
		*/
		virtual bool isSpeedRateSupported(int speed) const = 0;

		/**
		* get the Speed.
		* @return the speed
		*/
		virtual int getSpeed() const = 0;

		/**
		* sets the Speed.
		* @param speed the speed
		*/
		virtual void setSpeed(int speed) = 0;
	};
}
#endif