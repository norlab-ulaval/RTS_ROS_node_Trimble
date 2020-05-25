#ifndef POWERSOURCEEVENT_H_
#define POWERSOURCEEVENT_H_

#include "IPowerSource.h"

namespace SSI
{
	/**
	* Provides data for the ISsiPower::CurrentPowerSourceChanged event.
	* Use ISsiPower::GetPowerSources to receive a specific IPowerSource from the sensor.
	* @see ISsiPower.CurrentPowerSourceChanged
	* @see ISsiPower
	*/
	class PowerSourceEvent
	{
	public:
		/**
		* Initializes a new instance of the PowerSourceEvent class.
		* @param IPowerSource the power source
		*/
		PowerSourceEvent(IPowerSource& powerSource);

		/**
		* Uninitializes a instance of the PowerSourceEvent class.
		*/
		virtual ~PowerSourceEvent();

		/**
		* get the power source.
		* @return the power source
		*/
		IPowerSource& getPowerSource() const;
	private:
		PowerSourceEvent();
		PowerSourceEvent(const PowerSourceEvent& copyMe);
		PowerSourceEvent& operator=(const PowerSourceEvent&);
		IPowerSource& _powerSource; /** the power source */
	};
}
#endif
