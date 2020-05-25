#ifndef RTCMHEIGHTINDICATIONTYPE_H
#define RTCMHEIGHTINDICATIONTYPE_H

namespace SSI
{
	/**
	* Represents RTCM Datum Calculation Types. 
	*
	* @remarks The value of IDatumRtcmParameters.HeightIndicator will be one of these values.
	* @see IDatumRtcmParameters
	* @see ISsiRtkSurvey
	*/
	enum RtcmHeightIndicationType
	{
		/**
		* RTCM height indication type is geometric.
		*/
		RHIT_Geometric,

		/**
		* RTCM height indication type is local physical.
		*/
		RHIT_LocalPhysical,

		/**
		* RTCM height indication type is WGS84 physical.
		*/
		RHIT_WGS84Physical,

		/**
		* RTCM height indication type is unknown geoid.
		*/
		RHIT_UnknownGeoid
	};
}
#endif