#ifndef IRTCMONLINETRANSFORMATIONLISTENER_H
#define IRTCMONLINETRANSFORMATIONLISTENER_H

#include "DatumRtcmParametersUpdate.h"
#include "DatumRtcmGridResidualsUpdate.h"

namespace SSI
{
	/**
	* Listens for RTCM Online Transformation information event.
	*/
	class IRTCMOnlineTransformationListener
	{
	public:
		virtual ~IRTCMOnlineTransformationListener();

		/**
		* receives the event message when event occur.
		* @param parameters DatumRtcmParametersUpdate event
		*/
		virtual void onDatumRtcmParametersUpdate(const DatumRtcmParametersUpdate& parameters) = 0;

		/**
		* receives the event message when event occur.
		* @param residuals DatumRtcmGridResidualsUpdate event
		*/
		virtual void onDatumRtcmGridResidualsUpdate(const DatumRtcmGridResidualsUpdate& residuals) = 0;
	};
}
#endif