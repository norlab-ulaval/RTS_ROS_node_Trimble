#ifndef ICORRECTIONDATASOURCERTXVIAIPSETTINGS_H_
#define ICORRECTIONDATASOURCERTXVIAIPSETTINGS_H_

#include "ICorrectionDataSourceTCPSettings.h"
#include "TectonicPlateInfo.h"
#include "Coordinates.h"
#include "ReferenceFrame.h"
#include "RTXDataStream.h"
#include <vector>

namespace SSI
{
    /**
    * Represents Settings for establishing an RTX Via Ip Connection.
    */
    class ICorrectionDataSourceRTXViaIpSettings : public virtual ICorrectionDataSourceTCPSettings
    {
    public:
        virtual ~ICorrectionDataSourceRTXViaIpSettings();


        /*
        *  Lists the supported RTX correction data streams.
        *  @return Enumeration of supported RTX correction data streams
        */
        virtual std::vector<RTXDataStream> listSupportedRTXDataStreams()=0;

        /*
        * Gets RTX Data stream
        * @return RTX Data Stream
        */
        virtual RTXDataStream getStream()=0;

        /*
        * Sets RTX Data Stream
        * @param stream RTX Data Stream
        */
        virtual void setStream(RTXDataStream stream)=0;

    };
}
#endif
