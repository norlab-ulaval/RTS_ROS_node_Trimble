#ifndef ICORRECTIONDATASOURCESBASSETTINGS_H_
#define ICORRECTIONDATASOURCESBASSETTINGS_H_

#include "ICorrectionDataSource.h"

namespace SSI
{
	/**
	* Represents Settings for establishing an SBAS Connection.
	*/
	class ICorrectionDataSourceSBASSettings : public ICorrectionDataSource
	{
	public:
		~ICorrectionDataSourceSBASSettings();

		/**
		* Gets Wide Area Augmentation System (WAAS) is on.
		* @return the WAAS is enabled.
		*/
		virtual bool getWAAS() const = 0;

		/**
		* Enable Wide Area Augmentation System (WAAS)
		* @param on Enable
		*/
		virtual void setWAAS(bool on) = 0;

		/**
		* Gets European Geostationary Navigation Overlay Service (EGNOS) is on.
		* @return the EGNOS is enabled.
		*/
		virtual bool getEGNOS() const = 0;

		/**
		* Enable European Geostationary Navigation Overlay Service (EGNOS)
		* @param on Enable
		*/
		virtual void setEGNOS(bool on) = 0;

		/**
		* Gets GPS Aided Geo Augmented Navigation (GAGAN) is on.
		* @return the GAGAN is enabled.
		*/
		virtual bool getGAGAN() const = 0;

		/**
		* Enable GPS Aided Geo Augmented Navigation (GAGAN)
		* @param on Enable
		*/
		virtual void setGAGAN(bool on) = 0;

		/**
		* Gets Multi-functional Satellite Augmentation System (MSAS) is on.
		* @return the MSAS is enabled.
		*/
		virtual bool getMSAS() const = 0;

		/**
		* Enable Multi-functional Satellite Augmentation System (MSAS)
		* @param on Enable
		*/
		virtual void setMSAS(bool on) = 0;

		/**
		* Gets GLONASS System for Differential Correction and Monitoring (SDCM) is on.
		* @return the MSAS is enabled.
		*/
		virtual bool getSDCM() const = 0;

		/**
		* Enable GLONASS System for Differential Correction and Monitoring (SDCM)
		* @param on Enable
		*/
		virtual void setSDCM(bool on) = 0;
	};
}
#endif