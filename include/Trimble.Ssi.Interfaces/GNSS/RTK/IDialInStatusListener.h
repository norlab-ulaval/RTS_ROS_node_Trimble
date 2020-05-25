#ifndef IDIALINSTATUSLISTENER_H_
#define IDIALINSTATUSLISTENER_H_

#include "DialInStatusUpdate.h"

namespace SSI
{
	/**
	* Listens for changed Dial in status.
	*/
	class IDialInStatusListener
	{
	public:
		virtual ~IDialInStatusListener();

		/**
		* receives the event message when changes occur.
		* @param DialInStatusUpdate that occurred
		*/
		virtual void onDialInStatusChanged(const DialInStatusUpdate& dialInStatusUpdate) = 0;
	};
}
#endif