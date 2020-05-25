#ifndef ICORRECTIONDATARECEIVEDLISTENER_H_
#define ICORRECTIONDATARECEIVEDLISTENER_H_

#include "CorrectionDataReceivedUpdate.h"

namespace SSI
{
	/**
	* Listens for Correction data byte count.
	*/
	class ICorrectionDataReceivedListener
	{
	public:
		virtual ~ICorrectionDataReceivedListener(void);
	
		/**
		* receives the event message when changes occur.
		* @param CorrectionDataReceivedUpdate that occurred
		*/
		virtual void onCorrectionDataReceivedUpdate(CorrectionDataReceivedUpdate &ntripDataReceivedUpdate)=0;
	};
}
#endif