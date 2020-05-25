#ifndef ISENSORFIRMWAREPROPERTY_H_
#define ISENSORFIRMWAREPROPERTY_H_

#include "IValuedSensorProperty.h"
#include <string>

namespace SSI
{
	/**
	* Represents a sensor property about the sensor's firmware.
	* @see ISsiSensorProperties
	*/
	class ISensorFirmwareProperty : public IValuedSensorProperty<std::string>
	{
	public:
		virtual ~ISensorFirmwareProperty();
	};
}
#endif