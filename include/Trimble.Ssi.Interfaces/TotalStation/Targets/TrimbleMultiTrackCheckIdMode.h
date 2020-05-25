#ifndef TRIMBLEMULTITRACKCHECKIDMODE_H_
#define TRIMBLEMULTITRACKCHECKIDMODE_H_

namespace SSI
{
	/** Represents the mode which describes when the defined ID gets checked against the ID of the %Trimble multitrack target.
	* To get an enumeration of supported <see cref="TrimbleMultiTrackCheckIdMode"/> values, use <see cref="ITrimbleMultiTrackTarget.ListSupportedCheckIdModes"/>.
	* Use <see cref="ITrimbleMultiTrackTarget.CheckIdMode"/> to get or set the check id mode of the TrimbleMultiTrack target.
	* @see ISsiTargets
	*/
	enum TrimbleMultiTrackCheckIdMode
	{
		TMTCIM_Active,		/**< The instrument checks the id of the target for measuring and locking. */
		TMTCIM_SemiActive	/**< The instrument checks the id for locking the target id and for measuring the prism reflection. */
	};
}
#endif