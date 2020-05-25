#ifndef ITRIMBLEMULTITRACKTARGET_H_
#define ITRIMBLEMULTITRACKTARGET_H_

#include "IPrismIdTarget.h"
#include "TrimbleMultiTrackCheckIdMode.h"
#include <vector>

namespace SSI
{
	/** Represents a %Trimble MultiTrack 1000 target.
	* Part.No. 58003013, prism constant 10 mm.
	* @seeITrimbleMultiTrackPassiveTarget
	* @see ISsiTargets
	*/
	class ITrimbleMultiTrackTarget : public IPrismIdTarget
	{
	public:
		virtual ~ITrimbleMultiTrackTarget();

		/** Gets or sets the current target mode.
		* @return Mode of the current target.
		*/
		virtual TrimbleMultiTrackCheckIdMode getCheckIdMode() const = 0;

		/** Gets or sets the current target mode.
		* @param idMode Mode of the current target.
		*/
		virtual void setCheckIdMode(TrimbleMultiTrackCheckIdMode idMode) = 0;

		/** Returns a list of all target modes.
		* @return List of all target modes.
		*/
		virtual std::vector<TrimbleMultiTrackCheckIdMode> listSupportedCheckIdModes() const = 0;
	
		/**
		* is the check ID mode supported ?
		* @param check ID mode to check
		* @return true if it is otherwise false
		*/
		virtual bool isCheckIdModeSupported(TrimbleMultiTrackCheckIdMode checkIdMode) const = 0;
	};
}
#endif