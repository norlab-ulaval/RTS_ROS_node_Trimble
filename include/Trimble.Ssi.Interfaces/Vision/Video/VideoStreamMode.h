#ifndef VIDEOSTREAMMODE_H_
#define VIDEOSTREAMMODE_H_

namespace SSI
{
	/**
	* Defines VideoStreamModes
	*/
	enum VideoStreamMode
	{
		VSM_UDP = 0,  /**< Represents video stream mode UDP */
		VSM_RTP = 1   /**< Represents video stream mode RTP */
	};
}
#endif