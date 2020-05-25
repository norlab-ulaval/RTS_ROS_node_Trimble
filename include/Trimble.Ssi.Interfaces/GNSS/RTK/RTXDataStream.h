#ifndef RTXDATASTREAM_H_
#define RTXDATASTREAM_H_

/**
 * Represents the used RTX data stream.
 */
enum RTXDataStream
{
    /*
    * The RTX data stream will be automatically selected
    */
    RTXDataStream_RTXAUTO,

    /*
    * The RTXIP data stream contains clock, orbit and bias information of all available satellites.
    */
    RTXDataStream_RTXIP,

    /*
    * The RTXEU data stream contains in addition to the RTXIP standard messages also regional iono information for Europe.
    */
    RTXDataStream_RTXEU,

	/*
	* The RTXNA data stream contains in addition to the RTXIP standard messages also regional iono information for North America.
	*/
	RTXDataStream_RTXNA
};
#endif
