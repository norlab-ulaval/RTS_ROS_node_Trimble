#ifndef TARGETSTATE_H_
#define TARGETSTATE_H_

namespace SSI
{
	/** Represents the lock state of a target.
	* Use IPrismAdvancedTarget.State to obtain the current lock state of the target.
	* @see ISsiTargets
	*/
	enum TargetState
	{
		TS_Locked,	/** The target is locked. */
		TS_Unlocked	/** The target is not locked. */
	};
}
#endif