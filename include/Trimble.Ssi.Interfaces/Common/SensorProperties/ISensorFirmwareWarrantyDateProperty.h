#ifndef ISENSORFIRMWAREWARRANTYDATEPROPERTY_H_
#define ISENSORFIRMWAREWARRANTYDATEPROPERTY_H_

#include "IValuedSensorProperty.h"
namespace SSI
{
/**
 * Represents a sensor property about the sensor's firmware warranty date.
 * @see ISsiSensorProperties
 */
class ISensorFirmwareWarrantyDateProperty: public IValuedSensorProperty<long long>
{
public:
    virtual ~ISensorFirmwareWarrantyDateProperty();
};

} /* namespace SSI */

#endif /* ISENSORFIRMWAREWARRANTYDATEPROPERTY_H_ */
