#ifndef ILOGSTATICEPOCHS_H
#define ILOGSTATICEPOCHS_H

#include "ILogInfo.h"

namespace SSI
{
	/**
	* Interface for accessing static measured epochs.
	*/
	class ILogStaticEpochs : public ILogInfo
	{
	public:
		virtual ~ILogStaticEpochs(void);

		/**
		* Gets the epochs
		* @return
		* The epochs.
		*/
		virtual unsigned int getEpochs()=0;
	};
}
#endif
