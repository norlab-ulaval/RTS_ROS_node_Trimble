#ifndef TSOBSERVATIONTYPE_H_
#define TSOBSERVATIONTYPE_H_

namespace SSI
{
	/**
	* Represents types for observations.
	*/
	enum TSObservationType
	{
		OT_AngleObservation,				/**< observation of angles only */
		OT_DistanceObservation,				/**< observation of distance */
		OT_AngleObservationPrecision,		/** precision of observation of angles */
		OT_DistanceObservationPrecision,	/** precision observation of distance */
		OT_AngleObservationAccuracy,		/** accuracy of observation of angles */
		OT_DistanceObservationAccuracy,		/** accuracy observation of distance */
		OT_TiltObservation,					/** observation tilt */
		OT_TimeObservation					/** observation time */
	};
}
#endif