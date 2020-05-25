#ifndef ISSISENSORPROPERTIES_H_
#define ISSISENSORPROPERTIES_H_

#include "ISsiInterface.h"
#include "SensorPropertyType.h"
#include "ISensorProperty.h"

namespace SSI
{
	/**
	* Provides members to access sensor properties of an instrument.
	* For a brief description of features and usage of various ISsiInterface see [Guides: Interfaces](@ref Guides_Interfaces)
	*/
	class ISsiSensorProperties : public ISsiInterface
	{
	public:
		virtual ~ISsiSensorProperties();

		/**
		* Tries to get an ISensorProperty instance of type TSensorProperty.
		* @param SensorPropertyType the sensor property type
		* @return the sensor property
		*/
		virtual ISensorProperty* getProperty(SensorPropertyType sensorPropertyType) = 0;
	};
}
#endif