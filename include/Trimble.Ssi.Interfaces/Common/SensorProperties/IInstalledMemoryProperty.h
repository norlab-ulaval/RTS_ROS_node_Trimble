#ifndef IINSTALLEDMEMORYPROPERTYPROPERTY_H_
#define IINSTALLEDMEMORYPROPERTYPROPERTY_H_

#include "SensorProperties/IValuedSensorProperty.h"

namespace SSI
{
	/**
	* Represents a sensor property about the sensor's installed storage memory in bytes.
	* @see ISsiSensorProperties
	*/
	class IInstalledMemoryProperty : public IValuedSensorProperty<long long>
	{
	public:
		virtual ~IInstalledMemoryProperty();
	};
}
#endif