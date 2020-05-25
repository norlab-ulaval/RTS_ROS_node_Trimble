#ifndef IRESOLUTIONTIMEBASED_H
#define IRESOLUTIONTIMEBASED_H
#include "IScanResolution.h"

namespace SSI
{
	/**
	* Any scan resolution defined by a time limit. The instrument will try
	* to get the best possible scan in the allowed time.
	* @see Trimble.Ssi.Interfaces.Scanner.IScanResolution
	*/
	class IResolutionTimeBased : public IScanResolution
	{
	public:
		virtual ~IResolutionTimeBased();

		/**
		* Gets the time limit in seconds.
		* @return
		* The time limit.
		*
		*/
		virtual long getTimeLimit() = 0;

		/**
		* Sets the time limit in seconds.
		* @return
		* The time limit.
		*
		*/
		virtual void setTimeLimit(long timeLimit) = 0;

		/**
		* Gets the minimum time limit.
		* @return
		* The time limit minimum.
		*
		*/
		virtual long getTimeLimitMin() = 0;

		/**
		* Gets the maximum time limit.
		* @return
		* The time limit maximum.
		*
		*/
		virtual long getTimeLimitMax() = 0;
	};
}

#endif // IRESOLUTIONTIMEBASED_H
