#ifndef IMEASUREMENTPARAMETER_H_
#define IMEASUREMENTPARAMETER_H_

#include "MeasurementParameterType.h"

namespace SSI
{
	/**
	* Represents a basic measurement parameter providing information about its type.
	* Use ISsiMeasurement::CreateMeasurementParameter to create an IMeasurementParameter.
	* Using IMeasurementParameter, MeasurementSettings can be instanciated for use with ISsiMeasurement::Measure
	* @see MeasurementSettings
	* @see ISsiMeasurement
	*/
	class IMeasurementParameter
	{
	public:
		virtual ~IMeasurementParameter();
	
		/**
		* Get the measurement parameter type
		* @return the measurement parameter type
		*/
		virtual MeasurementParameterType getMeasurementParameterType() const = 0;
	};
}
#endif