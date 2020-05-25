#ifndef INUMBEROFCHANNELSPROPERTY_H_
#define INUMBEROFCHANNELSPROPERTY_H_

#include "SensorProperties/IValuedSensorProperty.h"

namespace SSI
{
	/**
	* Represents a sensor property about the gnss receivers numbers of channels.
	* @see ISsiSensorProperties
	*/
	class INumberOfChannelsProperty : public IValuedSensorProperty<int>
	{
	public:
		virtual ~INumberOfChannelsProperty();
	};
}
#endif