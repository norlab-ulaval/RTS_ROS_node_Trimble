#ifndef ISENSORSERIALNUMBERPROPERTY_H_
#define ISENSORSERIALNUMBERPROPERTY_H_

#include "IValuedSensorProperty.h"
#include <string>

namespace SSI
{
	/**
	* Represents a sensor property about the sensor's serial number.
	*  @see ISsiSensorProperties
	*/
	class ISensorSerialNumberProperty : public IValuedSensorProperty<std::string>
	{
	public:
		virtual ~ISensorSerialNumberProperty();
	};
}
#endif