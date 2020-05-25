#ifndef IELECTRONICBUBBLESTATELISTENER_H
#define IELECTRONICBUBBLESTATELISTENER_H

#include "ElectronicBubbleStateUpdate.h"

namespace SSI
{
	/**
	* Listens for changed position.
	*/
	class IElectronicBubbleStateListener
	{
	public:
		virtual ~IElectronicBubbleStateListener();

		/**
		* receives the event message when changes occur.
		* @param ElectronicBubbleStateUpdate that occurred
		*/
		virtual void onElectronicBubbleStateUpdate(const ElectronicBubbleStateUpdate& electronicBubbleStateUpdate) = 0;
	};
}
#endif