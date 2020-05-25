#ifndef ISSITRACKLIGHT_H_
#define ISSITRACKLIGHT_H_

#include "ISsiInterface.h"
#include "TrackLightState.h"
#include <vector>

namespace SSI
{
	/**
	* the states for track light.
	*/
	class ISsiTrackLight : public ISsiInterface
	{
	public:
		virtual ~ISsiTrackLight();

		/**
		* get all supported track light parameters.
		* @return the supported track light parameters
		*/
		virtual std::vector<TrackLightState> listSupportedTrackLightStates() const = 0;

		/**
		* check if the track light state is supported.
		* @param TrackLightState to check
		* @return true when it is otherwise false
		*/
		virtual bool isTrackLightStateSupported(TrackLightState state) const = 0;

		/**
		* get the track light state.
		* @return the track light state
		*/
		virtual TrackLightState getTrackLightState() const = 0;
	
		/**
		* set the track light state.
		* @param TrackLightState the track light state
		*/
		virtual void setTrackLightState(TrackLightState state) = 0;
	};
}
#endif