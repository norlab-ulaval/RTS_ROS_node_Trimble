#ifndef ILOGELEVATIONMASK_H_
#define ILOGELEVATIONMASK_H_

#include "ILogInfo.h"

namespace SSI
{
	/**
	* Interface for accessing the elevation mask.
	*/
	class ILogElevationMask: public ILogInfo
	{
	public:
		virtual ~ILogElevationMask();

		/**
		* Gets the elevation mask.
		* @return The elevation mask.
		*/
		virtual double getElevationMask()=0;
	};
}
#endif