#ifndef ISSITRACKING_H_
#define ISSITRACKING_H_

#include "ISsiInterface.h"
#include "../Targets/ITarget.h"
#include "ITrackingObservationsListener.h"
#include "ITrackingStateChangedListener.h"
#include "TrackingMode.h"
#include <vector>

namespace SSI
{
	/**
	*Provides members to start streaming of tracking measurements.
	* For a brief description of features and usage of various ISsiInterface see Guides: Interfaces.
	* The following table lists the accuracy for the Tracking measurements.
	* Instrument | Prism | DR
	* -----------|-------|---
	* %Trimble S3 | 5 mm + 2 ppm | 10 mm + 2 ppm
	* %Trimble S6 DR Plus | 4 mm + 2 ppm | 4 mm + 2 ppm
	* %Trimble S8 DR Plus | 4 mm + 2 ppm | 4 mm + 2 ppm
	* %Trimble S8 DR HP | 5 mm + 1 ppm | 10 mm + 2 ppm
	* %Trimble VX | 4 mm + 2 ppm | 4 mm + 2 ppm
	* For more information see the appropriate device manual.
	*/
	class ISsiTracking : public ISsiInterface
	{
	public:
		virtual ~ISsiTracking();

		/**
		* Returns an enumeration of all available <see cref="TrackingMode"/> values.
		* Use <see cref="TrackingMode"/> for start Tracking via <see cref="StartTracking(TrackingMode)"/>.
		* @return An enumeration of all available <see cref="TrackingMode"/> values.
		*/
		virtual std::vector<TrackingMode> listSupportedTrackingModes() const = 0;

		/**
		* Determines whether the specified mode is supported.
		* @param mode The mode.
		* @return true if it is, otherwise false
		*/
		virtual bool isTrackingModeSupported(TrackingMode mode) const = 0;

		/**
		* Determines whether the specified target is supported for starting tracking.
		* @param ITarget the target
		* @return true if the target is supported; otherwise, false
		*/
		virtual bool isTargetSupported(const ITarget& target) const = 0;

		/**
		* Determines whether the specified target is supported for starting tracking.
		* @param target The target.
		* @param speed The <see cref="TrackingMode"/> which is to be applied.
		* @return <c>true</c> if the target is supported; otherwise, <c>false</c>.
		*/
		virtual bool isTargetSupported(const ITarget& target, TrackingMode speed) const = 0;

		/**
		* register a listener.
		* @param ITrackingObservationsListener the listener
		*/
		virtual void addTrackingObservationsListener(ITrackingObservationsListener& listener) = 0;

		/**
		* unsubscribe a listener.
		* @param ITrackingObservationsListener the listener
		*/
		virtual void removeTrackingObservationsListener(ITrackingObservationsListener& listener) = 0;

		/**
		* register a listener.
		* @param ITrackingStateChangedListener the listener
		*/
		virtual void addTrackingStateChangedListener(ITrackingStateChangedListener& listener) = 0;

		/**
		* unsubscribe a listener.
		* @param ITrackingStateChangedListener the listener
		*/
		virtual void removeTrackingStateChangedListener(ITrackingStateChangedListener& listener) = 0;

		/**
		* Gets the state of the tracking.
		* @return The state of the tracking.
		*/
		virtual TrackingState getTrackingState() const = 0;

		/**
		* Starts the tracking of the current target.
		* New observations are reported through the NewTrackingObservations event.
		*/
		virtual void startTracking() = 0;

		/**
		* Starts the tracking of the current target. New observations are reported through the <see cref="NewTrackingObservations"/> event.
		* Starting the tracking, when it is is already active does not affect the state of the <see cref="ISsiTracking"/> instance.
		* For limitations based on the instruments capabilities check <see cref="IsTargetSupported(ITarget, TrackingMode)"/>.
		* @param speed The <see cref="TrackingMode"/> which is to be applied.
		*/
		virtual void startTracking(TrackingMode speed) = 0;
	
		/**
		* Stops the tracking of the current target.
		*/
		virtual void stopTracking() = 0;
	};
}
#endif