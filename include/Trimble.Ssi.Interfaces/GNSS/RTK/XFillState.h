#ifndef XFILLSTATE_H_
#define XFILLSTATE_H_

namespace SSI
{
	/*
	* Represents state of XFill feature.
	* @remark The value of XFillState Changed event will be one of these values.
	*/
	enum XFillState
	{
		/*
		* Indicates that XFill is not ready, either because its inactive, or no RTX session can be established.
		*/
		XFillState_NotReady,

		/*
		* Indicates that XFill is ready.
		*/
		XFillState_Ready,

		/*
		* Indicates that XFill is running.
		*/
		XFillState_Running
	};
}
#endif