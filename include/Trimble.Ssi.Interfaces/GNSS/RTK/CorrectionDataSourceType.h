#ifndef CORRECTIONDATASOURCETYPE_H_
#define CORRECTIONDATASOURCETYPE_H_

namespace SSI
{

	/*
	* Represents correction data source types.
	* @remarks To get an enumeration of supported CorrectionDataSourceType values, use ISsiRtkSurvey.ListSupportedCorrectionDataSourceTypes
	* @remarks Use ISsiRtkSurvey.CreateCorrectionDataSource to create an ICorrectionDataSource, which can be used to set the correction data source of the GNSS Receiver
	*/
	enum CorrectionDataSourceType
	{
		/*
		*  Represents a NTRIP correction data source.
		*/
		CorrectionDataSourceType_NTRIP,

		/*
		* Represents an GSM correction data source via internal modem.
		*/
		CorrectionDataSourceType_GSMInternal,

		/*
		* Represents an GSM correction data source.
		*/
		CorrectionDataSourceType_GSM,

		/*
		* Represents a Radio rover correction data source.
		*/
		CorrectionDataSourceType_RadioRover,

		/*
		* Represents a Radio base correction data source.
		*/
		CorrectionDataSourceType_RadioBase,

		/*
		* Represents a Bluetooth rover correction data source.
		*/
		CorrectionDataSourceType_BluetoothRover,

		/*
		* Represents a Bluetooth base correction data source.
		*/
		CorrectionDataSourceType_BluetoothBase,

		/*
		* Represents a RTX via Satellite correction data source.
		*/
		CorrectionDataSourceType_RTXViaSatellite,

		/*
		* Represents a NTRIP With VRS position correction data source.
		*/
		CorrectionDataSourceType_NTRIPWithVRSPosition,

		/*
		* Represents a SBAS correction data source.
		*/
		CorrectionDataSourceType_SBAS,

		/*
		* Represents a Direct IP correction data source.
		*/
		CorrectionDataSourceType_DirectIP,

		/*
		* Represents a Direct IP Base correction data source.
		*/
		CorrectionDataSourceType_DirectIPBase,

		/*
        * Represents a RTX via IP correction data source.
        */
        CorrectionDataSourceType_RTXViaIP,

        /*
        * Represents a TrimbleHub correction data source.
        */
        CorrectionDataSourceType_TrimbleHub,
	};
}
#endif
