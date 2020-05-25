#ifndef IAPPLICATIONLICENSE_H_
#define IAPPLICATIONLICENSE_H_

#include <string>

namespace SSI
{


/**
 *  Represents the application license providing members for obtaining allowed capabilities.
 */
class IApplicationLicense
{
public:
    virtual ~IApplicationLicense();

    /**
     * Gets the application ID.
     * @return The ID of the application.
     */
    virtual std::string getApplicationId() = 0;

    /**
     * Gets the serial number of the device loading the driver.
     * @return The serial number of the host.
     */
    virtual std::string getHostSerialNumber() = 0;

    /**
     * Validates the given sensor model.
     * If this license lists the given sensor model this method will return true.
     * If no model is listed in the license, this method will return true.
     * @param sensorModel The sensor model.
     * @return true if the license does not list any sensor model or the given model; otherwise, false.
     */
    virtual bool isSensorDriverAllowed(std::string sensorModel) = 0;

    /**
     * Exposes if advanced Gnss features are licensed
     * @return true if advanced Gnss features are licensed; otherwise false
     */
    virtual bool isGNSSAdvancedAllowed() = 0;

    /**
     * Exposes if advanced Totalstation features are licensed
     * @return true if advanced Totalstation features are licensed; otherwise false
     */
    virtual bool isTotalStationAdvancedAllowed() = 0;
};

} /* namespace SSI */

#endif /* IAPPLICATIONLICENSE_H_ */
