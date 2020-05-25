#ifndef IFIRMWAREUPDATERECOMMENDEDPROPERTY_H
#define IFIRMWAREUPDATERECOMMENDEDPROPERTY_H
#include "IValuedSensorProperty.h"

namespace SSI
{

	/**
	* Represents a sensor property which tells whether a fw update is recommended for the connected receiver.
	* @see ISsiSensorProperties
	*/
	class IFirmwareUpdateRecommendedProperty :public IValuedSensorProperty<bool>
	{
	public:
		IFirmwareUpdateRecommendedProperty();
		virtual ~IFirmwareUpdateRecommendedProperty();
	};
}

#endif // IFIRMWAREUPDATERECOMMENDEDPROPERTY_H
