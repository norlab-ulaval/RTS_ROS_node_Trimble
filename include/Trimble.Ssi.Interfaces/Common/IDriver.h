#ifndef IDRIVER_H_
#define IDRIVER_H_

#include "IDriverInformation.h"
#include "ISensor.h"
#include "IApplicationLicense.h"

namespace SSI
{
	/**
	* Represents a driver instance providing members for creating a sensor.
	* @see ISensor
	*/
	class IDriver
	{
	public:
		virtual ~IDriver();

		/**
		* Gets the IDriverInformation associated with this driver.
		* @see IDriverInformation
		* @return instance of an IDriverInformation
		*/
		virtual const IDriverInformation& getDriverInformation() const = 0;

		/**
        * Gets the application license.
        * @return The ID of the application.
        */
		virtual IApplicationLicense * getApplicationLicense() const =0;

        /**
        * Sets the application license.
        */
		virtual void setApplicationLicense(IApplicationLicense *) =0;

		/**
		* Creates a new instance of a sensor.
		* @return a new instance of a sensor.
		*/
		virtual ISensor& createSensor() = 0;

		/**
		* Destroys an instance of a sensor.
		* @param sensor to destroy.
		*/
		virtual void destroySensor(ISensor& sensor) = 0;
	};
}
#endif
