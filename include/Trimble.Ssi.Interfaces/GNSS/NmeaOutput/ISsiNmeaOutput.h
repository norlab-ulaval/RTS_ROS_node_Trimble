#ifndef ISSINMEAOUTPUT_H
#define ISSINMEAOUTPUT_H

#include "ISsiInterface.h"
#include "INmeaOutputSettings.h"
#include "INmeaOutputListener.h"
#include <vector>

namespace SSI
{
/**
 *  Provides methods to start Nmea Output on the connected receiver.
 */
class ISsiNmeaOutput: public ISsiInterface
{
public:
    virtual ~ISsiNmeaOutput();

    /**
     * register a listener for listening.
     * @param INmeaOutputListener to listen
     */
    virtual void addNmeaOutputListener(INmeaOutputListener& listener) = 0;

    /**
     * unsubscribe a listener from listening.
     * @param INmeaOutputListener to listen
     */
    virtual void removeNmeaOutputListener(INmeaOutputListener& listener) = 0;

    /**
     *  Lists the supported nmea device port.
     *
     *  @returns the port list
     */
    virtual std::vector<NmeaDevicePort> listSupportedNmeaDevicePort() const = 0;

    /**
     *  Determines whether the specified nmea output type is supported.
     */
    virtual bool isSupported(NmeaDevicePort nmeaDevicePort) const = 0;

    /**
     *  Configure NmeaOutput.
     *
     *  @param outputSettings The nmea output settings.
     */
    virtual void configureNmeaOutput(INmeaOutputSettings& outputSettings) = 0;

    /**
     *  Creates the nmea output settings.
     *
     *  @param nmeasDevicePort Device port of the nmea output.
     *  @returns the settings
     */
    virtual INmeaOutputSettings* createNmeaOutputSettings(NmeaDevicePort nmeasDevicePort) const = 0;
};
}
#endif
