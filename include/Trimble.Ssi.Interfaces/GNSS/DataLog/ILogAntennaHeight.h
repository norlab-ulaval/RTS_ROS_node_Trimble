#ifndef ILOGANTENNAHEIGHT_H_
#define ILOGANTENNAHEIGHT_H_

#include "ILogInfo.h"
#include "AntennaHeightConfiguration.h"

namespace SSI
{
	/**
	* Interface for accessing antenna height parameter.
	*/
	class ILogAntennaHeight: public ILogInfo
	{
	public:
		virtual ~ILogAntennaHeight();

		/**
		* Gets the height configuration.
		* @return The height configuration.
		*/
		virtual const AntennaHeightConfiguration& getHeightConfiguration()=0;
	};
}
#endif