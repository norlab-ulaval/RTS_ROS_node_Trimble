#ifndef ISSITILT_H_
#define ISSITILT_H_

#include "ISsiInterface.h"

#include "TiltState.h"
#include "ITiltChangedListener.h"
#include "ITiltStateChangedListener.h"
#include "IStreamingStateChangedListener.h"

#include <vector>

namespace SSI
{
	/**
	* Provides members to access the tilt sensor of an instrument.
	* For a brief description of features and usage of various ISsiInterface see [Guides: Interfaces](@ref Guides_Interfaces)
	*/
	class ISsiTilt : public ISsiInterface
	{
	public:
		virtual ~ISsiTilt();

		/**
		* register a tilt state changed listener.
		* @param ITiltStateChangedListener the listener
		*/
		virtual void addTiltStateChangedListener(ITiltStateChangedListener& listener) = 0;

		/**
		* unsubscribe a tilt state changed listener.
		* @param ITiltStateChangedListener the listener
		*/
		virtual void removeTiltStateChangedListener(ITiltStateChangedListener& listener) = 0;

		/**
		* register a tilt changed listener.
		* @param ITiltChangedListener the listener
		*/
		virtual void addTiltChangedListener(ITiltChangedListener& listener) = 0;

		/**
		* unsubscribe a tilt changed listener.
		* @param ITiltChangedListener the listener
		*/
		virtual void removeTiltChangedListener(ITiltChangedListener& listener) = 0;

		/**
		* register a tilt changed listener.
		* @param IStreamingStateChangedListener the listener
		*/
		virtual void addStreamingStateChangedListener(IStreamingStateChangedListener& listener) = 0;

		/**
		* unsubscribe a tilt changed listener.
		* @param IStreamingStateChangedListener the listener
		*/
		virtual void removeStreamingStateChangedListener(IStreamingStateChangedListener& listener) = 0;

		/**
		* gets the current streaming state.
		*/
		virtual StreamingState getStreamingState() const = 0;

		/**
		* Returns an enumeration of available tilt states.
		* Use this method to obtain the states that are possible results using GetTilt.
		* @return the available tilt states.
		*/
		virtual std::vector<TiltState> listSupportedTiltStates() const = 0;

		/**
		* check if the tilt state supported is.
		* @param TiltState to check
		* @return true when it is otherwise false
		*/
		virtual bool isTiltStateSupported(TiltState tiltState) const = 0;

		/**
		* Returns the next tilt value as an LevelTilt instance.
		* This method blocks until tilt values are available.
		* For a continuous stream of tilt values see TiltChanged.
		* @return the tilt value
		*/
		virtual const LevelTilt& getTilt() const = 0;

		/**
		* Starts the streaming of tilt values through the TiltChanged event.
		* Starting the streaming of tilt values, when the streaming is already active does not affect the state of the ISsiTilt instance.
		* To retrieve the current tilt values once, use the GetTilt method instead.
		*/
		virtual void startStreamingTiltValues() = 0;
	
		/**
		* Stops the streaming of tilt values through the TiltChanged event.
		* Stopping the streaming of tilt values, when the streaming is not active does not affect the state of the ISsiTilt instance.
		*/
		virtual void stopStreamingTiltValues() = 0;
	};
}
#endif