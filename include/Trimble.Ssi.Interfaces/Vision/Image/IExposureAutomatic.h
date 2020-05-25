#ifndef IEXPOSUREAUTOMATIC_H_
#define IEXPOSUREAUTOMATIC_H_

#include "IExposure.h"

namespace SSI
{
	/**
	* Represents exposure settings for automatic exposure regulation.
	*/
	class IExposureAutomatic : public IExposure
	{
	public:
		virtual ~IExposureAutomatic();
	};
}
#endif