#ifndef MEASUREMENTPARAMETERTYPE_H_
#define MEASUREMENTPARAMETERTYPE_H_

namespace SSI
{
	/**
	* Represents a type of measurement parameters.
	* Use ISsiMeasurement::CreateMeasurementParameter to create an IMeasurementParameter out of it's type.
	* @see ISsiMeasurement
	*/
	enum MeasurementParameterType
	{
		MPT_DistancePrecision,	/**< Type of the parameter, that enforces a measurement to reach a certain edm precision. A measurement parameter of this type always implements the IMeasurementParameterDistancePrecision interface. */
		MPT_Mode				/**< Type of the parameter, that enables the measurement to have varying durations. A measurement parameter of this type always implements the <see cref="IMeasurementParameterMode"/> interface. */
	};
}
#endif