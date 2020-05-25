#ifndef DIALINSTATUSUPDATE_H_
#define DIALINSTATUSUPDATE_H_

#include "GSMModemDialStatus.h"

namespace SSI
{
	/*
	*  Provides data for the ICorrectionDataSourceGSMBaseSettings.DialInStatusChanged event.
	*/
	class DialInStatusUpdate
	{
	public:
		/*
		* Initializes a new instance of the NtripConnectionStatusChangedEventArgs class.
		* @param GSMModemDialStatus
		*/
		DialInStatusUpdate(GSMModemDialStatus status);

		/*
		* Gets the status.
		* @return  GSMModemDialStatus
		*/
		GSMModemDialStatus getStatus() const;
	private:
		GSMModemDialStatus _status;
	};
}
#endif