#ifndef ITRIMBLE360TARGET_H_
#define ITRIMBLE360TARGET_H_

#include "IPrismIdTarget.h"
#include "Trimble360CheckIdMode.h"
#include <vector>

namespace SSI
{
	/** This interface represents the %Trimble 360° target.
	* Part.No. 58128001, prism constant 2 mm.
	* @see ITrimble360PassiveTarget
	* @see ISsiTargets
	*/
	class ITrimble360Target : public IPrismIdTarget
	{
	public:
		virtual ~ITrimble360Target();
		
		/** Gets or sets the current target mode.
		* @return Mode of the current target.
		*/
		virtual Trimble360CheckIdMode getCheckIdMode() const = 0;
		
		/** Gets or sets the current target mode.
		* @param idMode Mode of the current target.
		*/
		virtual void setCheckIdMode(Trimble360CheckIdMode idMode) = 0;

		/** Returns a list of all target modes.
		* @return List of all target modes.
		*/
		virtual std::vector<Trimble360CheckIdMode> listSupportedCheckIdModes() const = 0;
		
		/**
		* is the check ID mode supported ?
		* @param check ID mode to check
		* @return true if it is otherwise false
		*/
		virtual bool isCheckIdModeSupported(Trimble360CheckIdMode checkIdMode) const = 0;
	};
}
#endif