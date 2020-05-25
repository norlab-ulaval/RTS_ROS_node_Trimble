#ifndef IRECEIVERIDPROPERTY_H_
#define IRECEIVERIDPROPERTY_H_

#include "SensorProperties/IValuedSensorProperty.h"

namespace SSI
{
	/**
	* Represents a sensor property about the gnss receivers id
	* @see ISsiSensorProperties
	*/
	class IReceiverIdProperty : public IValuedSensorProperty<int>
	{
	public:
		virtual ~IReceiverIdProperty();
	};
}
#endif