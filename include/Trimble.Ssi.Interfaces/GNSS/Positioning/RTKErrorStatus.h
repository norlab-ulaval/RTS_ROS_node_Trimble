#ifndef RTKERRORSTATUS_H_
#define RTKERRORSTATUS_H_

namespace SSI
{
	/**
	* Represents RTKErrorStatus of @see IRTKStatusObservation.
	* The value of @see IRTKStatusObservation.RTKErrorStatus will be one of these values.
	* @see IRTKStatusObservation
	* @see ISsiPositioning
	*/
	enum RTKErrorStatus
	{
		RTKES_RadioLinkDown=5,					/**< Radio link down. May occur during periods when no base corrections are received. */
		RTKES_DataNotSynced,					/**< Data not synced. */
		RTKES_NoBaseStation,					/**< No base station. May occur if no base station is found given the configured parameters. */
		RTKES_LowRefStationSVSignalStrength=9,	/**< Low reference station SV signal strength. */
		RTKES_LowRoverSVSignalStrength,			/**< Low rover SV signal strength. */
		RTKES_WaitingForL2BaseData,				/**< Waiting for L2 base data. */
		RTKES_WaitingForL2SVsAtRover,			/**< Waiting for L2 SVs at rover. */
		RTKES_RMSExceedsLimit=14,				/**< Root mean square (RMS) exceeds limit. */
		RTKES_PDOPExceedsMask,					/**< PDOP exceeds mask. */
		RTKES_RTKUnableToInitialize=19,			/**< The RTK engine is unable to initialize. */
		RTKES_LessThan5SVs=22,					/**< Less than five common SV. */
		RTKES_InsufficientAveraging,			/**< Insufficient measurement averaging. */
		RTKES_InsufficientL2Measurement,		/**< Insufficient L2 measurement. */
		RTKES_NewBaseStationDetectedWait=31,    /**< New base station detected, wait for reference update. */
        RTKES_NoRTXOffshore=100                 /**< Can not do RTX because of Offshore. */
	};
}
#endif