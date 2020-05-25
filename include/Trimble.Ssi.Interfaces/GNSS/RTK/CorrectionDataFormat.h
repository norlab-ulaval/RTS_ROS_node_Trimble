#ifndef CORRECTIONDATAFORMAT_H_
#define CORRECTIONDATAFORMAT_H_

namespace SSI
{
	/*
	* Represents correction data format.
	* @remarks To get an enumeration of supported CorrectionDataFormat values, use ICorrectionDataSourceAdvanced.ListSupportedCorrectionDataFormats
	*/
	enum CorrectionDataFormat
	{
		/*
		* CorrectionDataFormat is RTCM 2.1.
		*/
		CorrectionDataFormat_RTCM21,

		/*
		* CorrectionDataFormat is RTCM 2.2.
		*/
		CorrectionDataFormat_RTCM22,

		/*
		* CorrectionDataFormat is RTCM 2.3.
		*/
		CorrectionDataFormat_RTCM23,

		/*
		* CorrectionDataFormat is RTCM 3.0.
		*/
		CorrectionDataFormat_RTCM30,

		/*
		* CorrectionDataFormat is RTCMVRS.
		*/
		CorrectionDataFormat_RTCMVRS,

		/*
		* CorrectionDataFormat is RTCMFKP.
		*/
		CorrectionDataFormat_RTCMFKP,

		/*
		* CorrectionDataFormat is CMR.
		*/
		CorrectionDataFormat_CMR,

		/*
		* CorrectionDataFormat is CMRPLUS.
		*/
		CorrectionDataFormat_CMRPLUS,

		/*
		* CorrectionDataFormat is CMRX.
		*/
		CorrectionDataFormat_CMRX,

		/*
		* CorrectionDataFormat is CMRVRS.
		*/
		CorrectionDataFormat_CMRVRS,

		/*
		* CorrectionDataFormat is RTCM 3.2.
		*/
		CorrectionDataFormat_RTCM32,

		/*
		* CorrectionDataFormat is ATOM STANDARD.
		*/
		CorrectionDataFormat_ATOM_STANDARD,

		/*
		* CorrectionDataFormat is ATOM COMPACT.
		*/
		CorrectionDataFormat_ATOM_COMPACT,

		/*
		* CorrectionDataFormat is ATOM Super COMPACT.
		*/
		CorrectionDataFormat_ATOM_SCOMPACT,

		/*
		* CorrectionDataFormat is CMRXVRS.
		*/
		CorrectionDataFormat_CMRXVRS,
	};
}
#endif