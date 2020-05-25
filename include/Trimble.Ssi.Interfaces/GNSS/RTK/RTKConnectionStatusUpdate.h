#ifndef RTKCONNECTIONSTATUSUPDATE_H_
#define RTKCONNECTIONSTATUSUPDATE_H_

#include "GPRSNtripStartStatus.h"

namespace SSI
{
	/*
	*  Provides data for the ICorrectionDataSourceNTRIPSettings.ConnectionStatusChanged event.
	*/
	class RTKConnectionStatusUpdate
	{
	public:
		/*
		* Initializes a new instance of the NtripConnectionStatusUpdate class.
		* @param GPRSNtripStartStatus
		*/
		RTKConnectionStatusUpdate(GPRSNtripStartStatus status);

		/*
		* Gets the status.
		* @return  GPRSNtripStartStatus
		*/
		GPRSNtripStartStatus getStatus() const;
	private:
		GPRSNtripStartStatus _status;
	};
}
#endif