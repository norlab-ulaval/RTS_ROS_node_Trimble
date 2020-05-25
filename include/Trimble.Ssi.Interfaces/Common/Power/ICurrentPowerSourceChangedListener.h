#ifndef ICURRENTPOWERSOURCECHANGEDLISTENER_H_
#define ICURRENTPOWERSOURCECHANGEDLISTENER_H_

#include "PowerSourceEvent.h"

namespace SSI
{
	/**
	* listens for power source changes.
	*/
	class ICurrentPowerSourceChangedListener
	{
	public:
		virtual ~ICurrentPowerSourceChangedListener();

		/**
		* the power source event fired.
		* @param powerSourceEvent the occured event
		*/
		virtual void onCurrentPowerSourceChanged(const PowerSourceEvent& powerSourceEvent) = 0;
	};
}
#endif