#ifndef IRTXINITIALIZATIONSTATELISTENER_H_
#define IRTXINITIALIZATIONSTATELISTENER_H_

#include "RTXInitializationStateUpdate.h"

namespace SSI
{
	class IRTXInitializationStateListener
	{
	public:
		virtual ~IRTXInitializationStateListener();

		/**
		* receives the event message when changes occur.
		* @param ReferenceStationUpdate that occurred
		*/
		virtual void onRTXInitializationStateUpdate(const RTXInitializationStateUpdate& rtxInitializationStateUpdate) = 0;
	};
}
#endif