#ifndef TRACKINGMODE_H_
#define TRACKINGMODE_H_

namespace SSI
{
	/**
	* Represents the speed of the tracking.
	* To get an enumeration of supported <see cref="TrackingMode"/> values, use <see cref="ISsiTracking.ListSupportedTrackingModes"/>.
	* Use <see cref="TrackingMode"/> together with <see cref="ISsiTracking.IsTargetSupported(ITarget,TrackingMode)"/> to obtain whether the current Target is supported for getting tracked with this speed.
	* Use <see cref="TrackingMode"/> together with <see cref="ISsiTracking.StartTracking(TrackingMode)"/> to start tracking with that given speed.
	* <seealso cref="IPrismAdvancedTarget"/>
	* <seealso cref="ISsiTargets"/>
	*/
	enum TrackingMode
	{
		TM_Normal,	/**< Normal tracking speed. */
		TM_TenHz,	/**< Tracking with 10 Observations per second. */
		TM_TwentyHz /**< Tracking with 20 Observations per second. */
	};
}
#endif