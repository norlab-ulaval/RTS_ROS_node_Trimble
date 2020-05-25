#ifndef MEASUREMENTSTATE_H_
#define MEASUREMENTSTATE_H_

namespace SSI
{
	/**
	* shows available MeasurementState.
	*/
	enum MeasurementState
	{
		MS_Measuring,		/**< The measuring */
		MS_NotMeasuring,	/**< The not measuring */
		MS_Cancelling		/**< The cancelling */
	};
}
#endif