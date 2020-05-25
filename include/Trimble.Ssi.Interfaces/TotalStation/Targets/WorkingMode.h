#ifndef WORKINGMODE_H_
#define WORKINGMODE_H_

namespace SSI
{
	/**
	* Represents the locking mode of prism targets.
	* To get an enumeration of supported WorkingMode values, use IPrismAdvancedTarget::ListSupportedWorkingModes.
	* Use IPrismAdvancedTarget::WorkingMode to get or set the working mode of the target.
	* @see IPrismAdvancedTarget
	* @see ISsiTargets
	*/
	enum WorkingMode
	{
		WM_Manual,		/**< The prism target will never be locked in this mode. */
		WM_Searchlock,	/**< The prism target will be locked after a successful search. If the target is lost, it needs a search to follow again. */
		WM_Autolock		/**< The locked prism target will always be followed. If a target appears in front of the telescope, the instrument will lock on. */
	};
}
#endif