#ifndef GPRSNTRIPSTARTSTATUS_H_
#define GPRSNTRIPSTARTSTATUS_H_

namespace SSI
{
	/*
	* Represents GPRS Ntrip connection intermedate status.
	*/
	enum GPRSNtripStartStatus
	{
		/*
		* Preparing NTRIP connection.
		*/
		GPRSNTRIP_Prepare = 0,

		/*
		* Checking PPP.
		*/
		GPRSNTRIP_CheckPPP,

		/*
		* Initializing PPP.
		*/
		GPRSNTRIP_InitPPP,

		/*
		* Checking pin.
		*/
		GPRSNTRIP_CheckPin,

		/*
		* Starting PPP.
		*/
		GPRSNTRIP_StartPPP,

		/*
		* PPP is running.
		*/
		GPRSNTRIP_PPPRunning,

		/*
		* Initializing NTRIP.
		*/
		GPRSNTRIP_InitNTRIP,

		/*
		* Starting NTRIP.
		*/
		GPRSNTRIP_StartNTRIP,

		/*
		* Waiting for correction data.
		*/
		GPRSNTRIP_WaitCorrectiondata,

		/*
		* NTRIP is running.
		*/
		GPRSNTRIP_NTRIPRunning,

		/*
		* Getting source table.
		*/
		GPRSNTRIP_GetSourceTable,

		/*
		* Getting source table count.
		*/
		GPRSNTRIP_GetSourceTableCount,

        /*
         * Starting RTX Via IP.
         */
        GPRSNTRIP_StartRTXViaIP,

        /*
         * RTX Via IP is running.
         */
        GPRSNTRIP_RTXViaIPRunning,

        /*
         * Starting RTX via satellite.
         */
        GPRSNTRIP_StartRTXViaSatellite,

        /*
         * RTX via satellite is running.
         */
        GPRSNTRIP_RTXViaSatelliteRunning,
	};
}
#endif