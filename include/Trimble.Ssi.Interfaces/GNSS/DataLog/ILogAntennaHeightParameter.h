#ifndef ILOGANTENNAHEIGHTPARAMETER_H_
#define ILOGANTENNAHEIGHTPARAMETER_H_

#include "ILogParameter.h"
#include "AntennaHeightConfiguration.h"

namespace SSI
{
	/**
	* Provides access to setter and getter for Log Antenna Height Parameter.
	*/
	class ILogAntennaHeightParameter: public ILogParameter
	{
	public:
		virtual ~ILogAntennaHeightParameter();

		/**
		* Sets the height configuration.
		* @return The height configuration.
		*/
		virtual AntennaHeightConfiguration* getHeightConfiguration()=0;
	
		/**
		* Sets the height configuration.
		* @return The height configuration.
		*/
		virtual void setHeightConfiguration(AntennaHeightConfiguration& heightConfiguration)=0;
	};
}
#endif