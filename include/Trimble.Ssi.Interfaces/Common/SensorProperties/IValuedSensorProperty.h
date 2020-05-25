#ifndef IVALUEDSENSORPROPERTY_H_
#define IVALUEDSENSORPROPERTY_H_

#include "ISensorProperty.h"

namespace SSI
{
	/**
	* Represents a basic generic sensor property with a TValue such as ISensorModelProperty,
	* ISensorSerialNumberProperty, ISensorFirmwareProperty and ISensorNameProperty.
	*@see ISsiSensorProperties
	*/
	template<class T>
	class IValuedSensorProperty : public ISensorProperty
	{
	public:
		/**
		* get the sensor properties value.
		* @return The type of the sensor property.
		*/
		virtual T getValue() const = 0;
	};
}
#endif