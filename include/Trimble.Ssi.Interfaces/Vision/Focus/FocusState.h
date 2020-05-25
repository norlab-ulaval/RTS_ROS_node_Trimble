#ifndef FOCUSSTATE_H_
#define FOCUSSTATE_H_

namespace SSI
{
	/**
	* Represents the state of the Focus.
	*/
	enum FocusState
	{
		FS_Idle,	/**< The idle focus state */
		FS_Focusing /**< The focusing focus state */
	};
}
#endif