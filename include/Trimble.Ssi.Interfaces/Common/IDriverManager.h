#ifndef IDRIVERMANAGER_H_
#define IDRIVERMANAGER_H_

#include "IDriver.h"
#include <string>

namespace SSI
{
	/**
	* managing of drivers.
	*/
	class IDriverManager
	{
	public:
		virtual ~IDriverManager();

		/**
		* loads a driver from the dynamic library.
		* @param libraryName name of the library
		* @param applicationLicense Application license
		* @return an instance to the requested driver
		*/
		virtual IDriver& loadDriver(std::string libraryName,IApplicationLicense * applicationLicense) = 0;

		/**
		* loads a driver from the dynamic library handle.
		* @param applicationLicense Application license
		* @return an instance to the requested driver
        * @remark This is method is marked for deletion in next versions.
		*/
		virtual IDriver& loadDriver(void *libraryHandle,IApplicationLicense * applicationLicense)=0;

		/**
		* free the driver
		* @param driver the driver
		*/
		virtual void freeDriver(IDriver* driver) = 0;

		/**
		* free the sensor
		* @param driver the driver
		* @param sensor the sensor
		*/
		virtual void freeSensor(IDriver* driver, ISensor* sensor) = 0;

		/**
		* Sets driver log file path.
		* @param driverLogFilePath Log file path
		*/
		virtual void setDriverLogFilePath(std::string driverLogFilePath)=0;

		/**
		* Gets driver log file path.
		* @return driverLogFilePath Log file path
		*/
		virtual std::string getDriverLogFilePath()=0;
		
	   /**
		*  Gets the application serial number
		*  @return Application serial number
		*  @remark used by iOS client
		*/
	   virtual std::string getSerialNumber()=0;
	};
}
#endif
