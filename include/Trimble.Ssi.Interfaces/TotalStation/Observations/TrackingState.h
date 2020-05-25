#ifndef TRACKINGSTATE_H_
#define TRACKINGSTATE_H_

namespace SSI
{
	/**
	* shows available Trackingstates.
	*/
	enum TrackingState
	{
		OTS_Starting,		/**< Tracking state is Starting. */
		OTS_Tracking,		/**< Tracking state is Tracking. */
		OTS_Stopping,		/**< Tracking state is Stopping. */
		OTS_NotTracking		/**< Tracking state is NotTracking. */
	};
}
#endif