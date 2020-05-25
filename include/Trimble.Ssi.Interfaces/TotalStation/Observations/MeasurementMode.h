#ifndef MEASUREMENTMODE_H_
#define MEASUREMENTMODE_H_

namespace SSI
{
	/**
	* Represents the mode of a measurement.
	* To get an enumeration of supported <see cref="MeasurementMode"/> values, use <see cref="IMeasurementParameterMode.ListSupportedMeasurementModes"/>.
	*/
	enum MeasurementMode
	{
		MM_Fine,	/**< Represents the default measurement mode */
		MM_Coarse	/**< Represents a fast and therefor coarse measurement mode */
	};
}
#endif