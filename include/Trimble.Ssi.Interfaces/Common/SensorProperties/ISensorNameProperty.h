#ifndef ISENSORNAMEPROPERTY_H_
#define ISENSORNAMEPROPERTY_H_

#include "IValuedSensorProperty.h"
#include <string>

namespace SSI
{
	/**
	* Represents a sensor property about the sensor's name.
	* @see ISsiSensorProperties
	*/
	class ISensorNameProperty : public IValuedSensorProperty<std::string>
	{
	public:
		virtual ~ISensorNameProperty();
	};
}
#endif