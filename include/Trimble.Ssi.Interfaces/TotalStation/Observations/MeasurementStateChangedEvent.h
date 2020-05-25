#ifndef MEASUREMENTSTATECHANGEDEVENT_H_
#define MEASUREMENTSTATECHANGEDEVENT_H_

#include "MeasurementState.h"

namespace SSI
{
	/**
	* Provides data for the <see cref="ISsiMeasurement.MeasurementStateChanged"/> event.
	* <seealso cref="ISsiMeasurement.MeasurementStateChanged"/>
	*/
	class MeasurementStateChangedEvent
	{
	public:
		/**
		* Initializes a new instance of the <see cref="MeasurementStateChangedEvent"/> class.
		* @param measurementState The measurement state.
		*/
		MeasurementStateChangedEvent(MeasurementState measurementstate);
		virtual ~MeasurementStateChangedEvent();

		/**
		* Gets the state of the attribute tracking.
		* @return The state of the attribute tracking.
		*/
		MeasurementState getMeasurementState() const;
	private:
		MeasurementStateChangedEvent();
		MeasurementStateChangedEvent(const MeasurementStateChangedEvent& copyMe);
		//MeasurementStateChangedEvent& operator=(const MeasurementStateChangedEvent&);
		MeasurementState _measurementState;
	};
}
#endif