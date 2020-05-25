#ifndef IIDLEANGLESCHANGEDLISTENER_H_
#define IIDLEANGLESCHANGEDLISTENER_H_

#include "IdleAnglesChangedEvent.h"

namespace SSI
{
	/**
	* Listens for changed idle angles.
	*/
	class IIdleAnglesChangedListener
	{
	public:
		virtual ~IIdleAnglesChangedListener();

		/**
		* receives the event message when changes occur.
		* @param IdleAnglesChangedEvent the event that occured
		*/
		virtual void onIdleAnglesChanged(const IdleAnglesChangedEvent& idleAnglesChangedEvent) = 0;
	};
}
#endif
