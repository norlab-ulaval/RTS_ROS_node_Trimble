#ifndef ILOGFILEPARAMETER_H_
#define ILOGFILEPARAMETER_H_

#include "ILogParameter.h"
#include <string>

namespace SSI
{
	/**
	* Provides access to setter and getter for Log File Parameter.
	*/
	class ILogFileParameter : public ILogParameter
	{
	public:
		virtual ~ILogFileParameter();

        /**
        * Gets the path of the file.
        * @return The path of the file.
        */
        virtual std::string getFilePath() = 0;

        /**
        * Sets the path of the file.
        * @param The path of the file.
        */
        virtual void setFilePath(std::string filePath) = 0;

        /**
        * Gets the name of the file.
        * @return The name of the file.
        */
        virtual std::string getFileName() = 0;

        /**
        * Sets the name of the file.
        * @param The name of the file.
        */
        virtual void setFileName(std::string fileName) = 0;
	};
}
#endif