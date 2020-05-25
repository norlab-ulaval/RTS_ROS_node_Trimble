#ifndef TILTSTATE_H_
#define TILTSTATE_H_

namespace SSI
{
	/**
	* Represents the state of a tilt sensor.
	* To get an enumeration of supported TiltState values, use ISsiTilt::ListSupportedTiltStates.
	* Use ISsiTilt::GetTilt to obtain the current tilt as an LevelTilt instance, which also holds the current tilt state as LevelTilt::State.
	* @see ISsiTilt
	*/
	enum TiltState
	{
		TS_Ok,					/** The tilt is in range. */
		TS_OutOfRange,			/** The tilt is out of range. */
		TS_Unknown,				/** The tilt state is not known. */
		TS_NeedsCalibration,	/** The instrument needs to be calibrated. */
		TS_NeedsCheck			/** The instrument needs to be checked. */
	};
}
#endif