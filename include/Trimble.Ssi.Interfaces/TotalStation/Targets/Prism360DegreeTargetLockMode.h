#ifndef PRISM360DEGREETARGETLOCKMODE_H_
#define PRISM360DEGREETARGETLOCKMODE_H_


namespace SSI
{
	/** Represents the mode which optimizes the vertical angle accuracy on short ranges.
	* To get an enumeration of supported <see cref="Prism360DegreeTargetLockMode"/> values, use <see cref="IPrism360DegreeTarget.ListSupportedTargetLockModes"/>.
	* @see ISsiTargets
	*/
	enum Prism360DegreeTargetLockMode
	{
		PTLM_Active,								/**< Normal locking mode. */
		PTLM_ShortRangeOptimization					/**< The short range optimization is on. */
	};
}
#endif