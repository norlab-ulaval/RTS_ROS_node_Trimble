#ifndef IILOGINFOLISTENER_H_
#define IILOGINFOLISTENER_H_

#include "LogInfoUpdate.h"

namespace SSI
{
	/**
	* Listens for changed position.
	*/
	class ILogInfoListener
	{
	public:
		virtual ~ILogInfoListener();

		/**
		* receives the event message when changes occur.
		* @param LogInfoingObservationUpdate that occurred
		*/
		virtual void onLogInfoUpdate(const LogInfoUpdate& logInfoUpdate) = 0;
	};
}
#endif