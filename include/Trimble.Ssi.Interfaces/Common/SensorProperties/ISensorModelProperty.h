#ifndef ISENSORMODELPROPERTY_H_
#define ISENSORMODELPROPERTY_H_

#include "IValuedSensorProperty.h"
#include <string>

namespace SSI
{
	/**
	* Represents a sensor property about the sensor's model ID.
	* @see ISsiSensorProperties
	*/
	class ISensorModelProperty : public IValuedSensorProperty<std::string>
	{
	public:
		virtual ~ISensorModelProperty();
	};
}
#endif