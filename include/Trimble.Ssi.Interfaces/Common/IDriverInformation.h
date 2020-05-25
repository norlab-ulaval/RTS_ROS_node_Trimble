#ifndef IDRIVERINFORMATION_H_
#define IDRIVERINFORMATION_H_

#include <string>

namespace SSI
{
	/**
	* Represents meta data information for a specific driver.
	* Use IDriver::getInformation to access
	* @see IDriver
	*/
	class IDriverInformation
	{
	public:
		virtual ~IDriverInformation();

		/**
		* Get the unique identifier of the driver.
		* @return the unique Id
		*/
		virtual const std::string getUniqueId() const = 0;

		/**
		* Get the driver name.
		* @return the driver name
		*/
		virtual const std::string getDisplayName() const = 0;

		/**
		* Get the driver version
		* @return the version
		*/
		virtual const std::string getVersion() const = 0;

		/**
		* Get the copyright information of the driver
		* @return the copyright information
		*/
		virtual const std::string getCopyright() const = 0;

		/**
		* Get the name used in the license file.
		* @return the license name
		*/
		virtual const std::string getLicenseName() const = 0;
	};
}
#endif