#ifndef ITILTVALUESLISTENER_H
#define ITILTVALUESLISTENER_H

#include "TiltValuesUpdate.h"

namespace SSI
{
	/**
	* Listens for changed position.
	*/
	class ITiltValuesListener
	{
	public:
		virtual ~ITiltValuesListener();

		/**
		* receives the event message when changes occur.
		* @param TiltValuesUpdate that occurred
		*/
		virtual void onTiltValuesUpdate(const TiltValuesUpdate& tiltValueUpdate) = 0;
	};
}
#endif