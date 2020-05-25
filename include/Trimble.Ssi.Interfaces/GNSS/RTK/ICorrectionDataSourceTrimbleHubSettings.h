#ifndef ICORRECTIONDATASOURCETRIMBLEHUBSETTINGS_H_
#define ICORRECTIONDATASOURCETRIMBLEHUBSETTINGS_H_

#include "ICorrectionDataSource.h"
#include "CorrectionDataFormat.h"
#include "IRTKConnectionStatusListener.h"
#include <string>

namespace SSI
{
	/**
	* Represents Settings for establishing an RTX Via Satellite Connection.
	*/
	class ICorrectionDataSourceTrimbleHubSettings : public virtual ICorrectionDataSource
	{
	public:
		virtual ~ICorrectionDataSourceTrimbleHubSettings();

        /**
         * Gets the local settings option.
         * @returns The local settings option.
         */
        virtual bool getUseLocalSettings() const = 0;

        /**
        * Sets the local settings option.
        * @params on Tune on the local settings option.
        */
        virtual void setUseLocalSettings(bool on) = 0;

        /**
         * Gets the fallback option.
         * @returns The fallback option.
         */
        virtual bool getUseRTXFallBack() const = 0;

        /**
        * Sets the fallback option.
        * @params on Turn on the fallback option.
        */
        virtual void setUseRTXFallBack(bool on) = 0;

        /**
         * Gets the monitor survey option.
         * @returns The monitor survey option.
         */
        virtual bool getUseSurveyMonitor() const = 0;

        /**
        * Sets the monitor survey option.
        * @params on Turn on the monitor survey option.
        */
        virtual void setUseSurveyMonitor(bool on) = 0;

        /**
        * register a listener for listening RTK connection status.
        * @param IRTKConnectionStatusListener to listen
        */
        virtual void addConnectionStateListener(IRTKConnectionStatusListener& listener) = 0;

        /**
        * register a listener for listening RTK connection status.
        * @param IRTKConnectionStatusListener to listen
        */
        virtual void removeConnectionStateListener(IRTKConnectionStatusListener& listener) = 0;
        
        /**
        * Internal use interfaces 
        * LocalSettings get from upper level
        */
        enum LocalCorrectionType
        {
            LocalCorrectionType_Unknown,
            LocalCorrectionType_NTRIP,
            LocalCorrectionType_DirectIP
        };

        virtual LocalCorrectionType getLocalCorrectionType() const = 0;
        virtual void setLocalCorrectionType(LocalCorrectionType correctionType) = 0;

        virtual std::string getLocalServerAddress() const = 0;
        virtual void setLocalServerAddress(const std::string& address) = 0;

        virtual int getLocalServerPort() const = 0;
        virtual void setLocalServerPort(int port) = 0;

        virtual std::string getLocalUser() const = 0;
        virtual void setLocalUser(const std::string& user) = 0;

        virtual std::string getLocalPassword() const = 0;
        virtual void setLocalPassword(const std::string& password) = 0;

        virtual std::string getLocalMountPoint() const = 0;
        virtual void setLocalMountPoint(const std::string& mountPoint) = 0;

        virtual CorrectionDataFormat getLocalCorrectionDataFormat() const = 0;
        virtual void setLocalCorrectionDataFormat(CorrectionDataFormat correctionDataFormat) = 0;
	};
}
#endif
