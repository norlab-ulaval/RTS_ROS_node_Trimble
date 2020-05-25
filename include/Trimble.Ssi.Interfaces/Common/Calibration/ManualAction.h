#ifndef MANUALACTION_H_
#define MANUALACTION_H_

namespace SSI
{
	/**
	* Represents an action which is to be run by the user manually.
	*/
	enum ManualAction
	{
		MA_AimToTarget, /**< Represents a manual action that requests the user to manually aim a certain target */
		MA_Rotate3D,    /**< Represents a manual action that requests the user to rotate the instrument slowly */
		MA_Rotate,      /**< Represents a manual action that requests the user to rotate the instrument slowly around all axis */
		MA_MeasureLoop  /**< Represents a manual measure loop operation */
	};
}
#endif
