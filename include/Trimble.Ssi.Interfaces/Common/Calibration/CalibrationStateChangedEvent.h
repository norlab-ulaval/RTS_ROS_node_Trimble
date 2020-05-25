#ifndef CALIBRATIONSTATECHANGEDEVENT_H_
#define CALIBRATIONSTATECHANGEDEVENT_H_

#include "CalibrationState.h"

namespace SSI
{
	/**
	* An event that occurs when the State of a Calibration step changes.
	*/
	class CalibrationStateChangedEvent
	{
	public:
		/**
		* Initializes a new instance of the <see cref="CalibrationStateChangedEvent"/> class.
		* @param state The state.
		*/
		CalibrationStateChangedEvent(CalibrationState state);

		/**
		* Uninitializes a instance of the <see cref="CalibrationStateChangedEvent"/> class.
		*/
		virtual ~CalibrationStateChangedEvent();

		/**
		* Gets the state.
		* @return The state.
		*/
		CalibrationState getState() const;
	private:
		/**
		* Sets the state.
		* @param state The state
		*/
		void setState(CalibrationState state);
		CalibrationState _state; //< the calibration state
	};
}
#endif
