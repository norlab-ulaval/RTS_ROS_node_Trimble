#ifndef XFILLRTXSTATEUPDATE_H_
#define XFILLRTXSTATEUPDATE_H_

#include "XFillRTXState.h"

namespace SSI
{
	/*
	* Provides data for the XFillRTXState Changed event.
	*/
	class XFillRTXStateUpdate
	{
	public:
	
		/*
		* Initializes a new instance of the XFillRTXStateUpdate class.
		* @param XFillRTXState
		*/
		XFillRTXStateUpdate(XFillRTXState state);

		/*
		* Gets the state.
		* @return XFillRTXState
		*/
		XFillRTXState getState() const;
	private:
		XFillRTXState _state;
	};
}
#endif