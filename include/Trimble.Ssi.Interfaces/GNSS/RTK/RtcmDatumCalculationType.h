#ifndef RTCMDATUMCALCULATIONTYPE_H
#define RTCMDATUMCALCULATIONTYPE_H

namespace SSI
{
	/**
	* Represents RTCM Datum Calculation Types. 
	*
	* @remarks The value of IDatumRtcmParameters.ComputationIndicator will be one of these values.
	* @see IDatumRtcmParameters
	* @see ISsiRtkSurvey
	*/
	enum RtcmDatumCalculationType
	{
		/**
		* RTCM Datum calculation type is approximate seven parameter.
		*/
		RDCT_ApproxSevenparam,

		/**
		* RTCM Datum calculation type is exact seven parameter.
		*/
		RDCT_ExactSevenparam,

		/**
		* RTCM Datum calculation type is abridged MOLO.
		*/
		RDCT_AbridgedMolo,

		/**
		* RTCM Datum calculation type is BADEKAS MOLO.
		*/
		RDCT_BadekasMolo,

		/**
		* RTCM Datum calculation type is datum unknown.
		*/
		RDCT_DatumUnknown
	};
}
#endif