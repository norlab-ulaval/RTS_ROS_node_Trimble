#ifndef ITARGETCHANGEDLISTENER_H_
#define ITARGETCHANGEDLISTENER_H_

#include "TargetChangedEvent.h"

namespace SSI
{
	/**
	* listens for changed targets.
	*/
	class ITargetChangedListener
	{
	public:
		virtual ~ITargetChangedListener();
	
		/**
		* process the occurred event
		* @param TargetChangedEvent the event
		*/
		virtual void targetChanged(const TargetChangedEvent& event) = 0;
	};
}
#endif