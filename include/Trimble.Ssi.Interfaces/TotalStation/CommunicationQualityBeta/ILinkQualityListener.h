#ifndef ILINKQUALITYLISTENER_H_
#define ILINKQUALITYLISTENER_H_

#include "LinkQualityEvent.h"

namespace SSI
{
	/**
	* listens for link quality updates.
	*/
	class ILinkQualityListener
	{
	public:
		virtual ~ILinkQualityListener();

		/**
		* process the occurred event
		* @param the event
		*/
		virtual void linkQuality(const LinkQualityEvent& event) = 0;
	};
}
#endif
