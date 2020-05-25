#ifndef ISSIMEASUREMENT_H_
#define ISSIMEASUREMENT_H_

#include "ISsiInterface.h"

#include "MeasurementType.h"
#include "MeasurementState.h"
#include "MeasurementParameterType.h"
#include "MeasurementSettings.h"
#include "IMeasurementParameter.h"
#include "TSObservationContainer.h"
#include "IMeasurementStateChangedListener.h"

#include <vector>

namespace SSI
{
	/**
	* Provides information to start a measurement.
	*/
	class ISsiMeasurement : public ISsiInterface
	{
	public:
		virtual ~ISsiMeasurement();

		/**
		* register a listener.
		* @param IMeasurementStateChangedListener the listener
		*/
		virtual void addMeasurementStateChangedListener(IMeasurementStateChangedListener& listener) = 0;

		/**
		* unsubscribe a listener.
		* @param IMeasurementStateChangedListener the listener
		*/
		virtual void removeMeasurementStateChangedListener(IMeasurementStateChangedListener& listener) = 0;

		/**
		* Gets the state of the idle angle.
		* @return The state of the idle angle.
		*/
		virtual MeasurementState getMeasurementState() const = 0;

		/**
		* Returns all available measurement types.
		* Use MeasurementType together with MeasurementSettings for measuring via Measure.
		* @return the available measurement types.
		*/
		virtual std::vector<MeasurementType> listSupportedMeasurementTypes() const = 0;

		/**
		* is the measurement type supported.
		* @param measurementType MeasurementType to check
		* @return if it is otherwise false
		*/
		virtual bool isMeasurementTypeSupported(MeasurementType measurementType) const = 0;

		/**
		* Returns all available measurement parameter types which are available for that measurement type.
		* @return the available measurement parameter types
		*/
		virtual std::vector<MeasurementParameterType> listSupportedMeasurementParameterTypes(MeasurementType measurementType) const = 0;

		/**
		* is the measurement parameter type supported.
		* @param MeasurementParameterType to check
		* @return if it is otherwise false
		*/
		virtual bool isMeasurementParameterSupported(MeasurementType measurementType, MeasurementParameterType measurementParameterType) const = 0;

		/**
		* Creates an instance of IMeasurementParameter based on a specified MeasurementParameterType.
		* @param MeasurementParameterType
		* @return IMeasurementParameter associated with the specified MeasurementType.
		*/
		virtual IMeasurementParameter* createMeasurementParameter(MeasurementParameterType parameterType) const = 0;

		/**
		* Starts measuring using the specified measurementSettings.
		* @param MeasurementSettings measurement settings.
		* @return Result of the measurement as ObservationContainer.
		*/
		virtual TSObservationContainer measure(MeasurementSettings& settings) = 0;


		/**
		* Returns the last measurement data. Used when measure throws @see InvalidMeasurementException
		* @return last measurement data as ObservationContainer.
		*/
		virtual TSObservationContainer getLastMeasurementData() = 0;

		/**
		* Cancels a pending measurement operation.
		* Cancellation of a measurement, which has not been started yet does not affect the state
		* of the ISsiMeasurement instance.
		*/
		virtual void cancelMeasure() = 0;
	};
}
#endif