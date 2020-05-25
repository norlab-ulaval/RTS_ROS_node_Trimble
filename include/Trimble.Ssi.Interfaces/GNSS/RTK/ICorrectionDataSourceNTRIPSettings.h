#ifndef ICORRECTIONDATASOURCENTRIPSETTINGS_H_
#define ICORRECTIONDATASOURCENTRIPSETTINGS_H_

#include "ICorrectionDataSourceAdvanced.h"
#include "IMountPointRequestCallback.h"
#include "ICorrectionDataSourceTCPSettings.h"
#include <vector>
#include <string>

namespace SSI
{
	/*
	* Represents correction data source NTRIP settings.
	*/
	class ICorrectionDataSourceNTRIPSettings : public ICorrectionDataSourceTCPSettings, public virtual ICorrectionDataSourceAdvanced
	{
	public:
		virtual ~ICorrectionDataSourceNTRIPSettings();

		/**
		* register the call back for selecting from a list of mount points.
		* @param IMountPointRequestCallback to receive and select mount point
		*/
		virtual void setMountPointRequestCallback(IMountPointRequestCallback* callback) = 0;

		/**
		* remove the call back for selecting from a list of mount points.
		*/
		virtual void removeMountPointRequestCallback() = 0;

		/*
		* Gets the user.
		* @return NTRIP user
		*/
		virtual const std::string& getUser() const=0;

		/*
		* Sets the user.
		* @param user NTRIP user
		*/
		virtual void setUser(std::string user)=0;

		/*
		* Gets the password.
		* @return password
		*/
		virtual const std::string& getPassword() const=0;

		/*
		* Sets the password.
		* @param password NTRIP password
		*/
		virtual void setPassword(std::string password)=0;

		/*
		* Gets the mount point.
		* @return mount point string
		*/
		virtual const std::string& getMountPoint() const=0;

		/*
		* Sets the mount point.
		* @param mountPoint NTRIP mount point
		*/
		virtual void setMountPoint(std::string mountPoint)=0;

	};
}
#endif
