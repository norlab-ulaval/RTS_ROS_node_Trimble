#ifndef TARGETCHANGEDEVENT_H_
#define TARGETCHANGEDEVENT_H_

#include "ITarget.h"

namespace SSI
{
	/**
	* Provides data for the ISsiTargets::TargetChanged event.
	* @see ISsiTargets.TargetChanged
	* @see ISsiTargets
	*/
	class TargetChangedEvent
	{
	public:
		/**
		* create a new target changed event.
		* @param the target
		*/
		TargetChangedEvent(ITarget& target);
		virtual ~TargetChangedEvent();

		/**
		* get the target.
		* @return the target
		*/
		ITarget& getTarget() const;

	private:
		TargetChangedEvent();
		TargetChangedEvent(const TargetChangedEvent& copyMe);
		TargetChangedEvent& operator=(const TargetChangedEvent&);
		ITarget& _target; /** the target */
	};
}
#endif