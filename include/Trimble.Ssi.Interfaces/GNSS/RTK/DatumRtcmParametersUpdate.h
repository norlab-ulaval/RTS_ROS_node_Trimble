#ifndef DATUMRTCMPARAMETERSUPDATE_H
#define DATUMRTCMPARAMETERSUPDATE_H

#include "IDatumRtcmParameters.h"

namespace SSI
{
	/**
	* Provides data for the DatumRtcmParametersUpdate event.
	*/
	class DatumRtcmParametersUpdate
	{
	public:
		~DatumRtcmParametersUpdate();

		/**
		* Initializes a new instance of the DatumRtcmParametersUpdate class.
		*
		* @param parameters The parameters.
		*/
		DatumRtcmParametersUpdate(IDatumRtcmParameters& parameters);

		/**
		* Gets the datum RTCM parameters.
		*
		* @return The datum RTCM parameters.
		*/
		IDatumRtcmParameters& getDatumRTCMParameters() const;
	private:
		IDatumRtcmParameters& _datumRtcmParameters;
	};
}
#endif