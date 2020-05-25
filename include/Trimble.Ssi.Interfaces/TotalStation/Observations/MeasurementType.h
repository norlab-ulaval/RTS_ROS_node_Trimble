#ifndef MEASUREMENTTYPE_H_
#define MEASUREMENTTYPE_H_

namespace SSI
{
	/**
	* Represents types for measurements.
	*/
	enum MeasurementType
	{
		MT_Angles,				/**< measurement of angles only */
		MT_AnglesAndDistance	/**< measuremnt of angles and distance */
	};
}
#endif