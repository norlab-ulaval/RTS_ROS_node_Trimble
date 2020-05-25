#ifndef XFILLRTXSTATE_H_
#define XFILLRTXSTATE_H_

namespace SSI
{
	/*
	* Represents state of XFillRTX feature.
	* @remark The value of XFillRTXState Changed event will be one of these values.
	*/
	enum XFillRTXState
	{
		/*
		* Indicates that XFillRTX is not ready, either because its inactive, or no RTX session can be established.
		*/
		XFillRTXState_NotReady,

		/*
		* Indicates that XFillRTX is ready.
		*/
		XFillRTXState_Ready,

		/*
		* Indicates that XFillRTX is running.
		*/
		XFillRTXState_Running
	};
}
#endif