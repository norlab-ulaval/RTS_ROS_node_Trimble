#ifndef XFILLSTATEUPDATE_H_
#define XFILLSTATEUPDATE_H_

#include "XFillState.h"

namespace SSI
{
	/*
	* Provides data for the XFillState Changed event.
	*/
	class XFillStateUpdate
	{
	public:
	
		/*
		* Initializes a new instance of the XFillStateUpdate class.
		* @param XFillState
		*/
		XFillStateUpdate(XFillState state);

		/*
		* Gets the state.
		* @return XFillState
		*/
		XFillState getState() const;
	private:
		XFillState _state;
	};
}
#endif