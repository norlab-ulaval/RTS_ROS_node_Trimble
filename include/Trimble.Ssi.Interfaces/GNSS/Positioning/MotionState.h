#ifndef MOTIONSTATE_H_
#define MOTIONSTATE_H_

namespace SSI
{
	/**
	* Represents Motion states for <see cref="IPositioningParameterMotionState"/>.
	* It decides whether the observations are getting enhanced by mean value calculation (static) or not.
	* One of these values is used to set the <see cref="IPositioningParameterMotionState.State"/>
	* <seealso cref="IPositioningParameterMotionState"/>
	* <seealso cref="IPositioningParameter"/>
	* <seealso cref="ISsiPositioning"/>
	*/
	enum MotionState
	{
		MS_Roving,	        /**< Motion state is roving. */
		MS_Static,	        /**< Motion state is static. */
        MS_PoleTipStatic    /**< Motion state is pole tip static. For ISsiTiltedMeasurement*/
	};
}
#endif