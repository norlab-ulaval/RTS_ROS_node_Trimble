#ifndef DATUMRTCMGRIDRESIDUALSUPDATE_H
#define DATUMRTCMGRIDRESIDUALSUPDATE_H

#include "IDatumRtcmGridResiduals.h"

namespace SSI
{
	/**
	* Provides data for the DatumRTCMGridResidualsUpdate event.
	*/
	class DatumRtcmGridResidualsUpdate
	{
	public:
		/**
		* Initializes a new instance of the DatumRtcmGridResidualsUpdate class.
		*
		* @param residuals The residuals.
		*/
		DatumRtcmGridResidualsUpdate(IDatumRtcmGridResiduals& residuals);
		~DatumRtcmGridResidualsUpdate();

		/**
		* Gets the datum RTCM grid residuals.
		*
		* @return The datum RTCM grid residuals.
		*/
		IDatumRtcmGridResiduals& getDatumRTCMGridResiduals() const;
	private:
		IDatumRtcmGridResiduals& _datumRTCMGridResiduals;
	};
}
#endif