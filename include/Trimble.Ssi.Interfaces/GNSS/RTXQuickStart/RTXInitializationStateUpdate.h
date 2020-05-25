#ifndef RTXINITIALIZATIONSTATEUPDATE_H_
#define RTXINITIALIZATIONSTATEUPDATE_H_

#include "RTXInitializationState.h"

namespace SSI
{
	/*
	* Provides data for the RTXInitializationState Changed  event.
	*/
	class RTXInitializationStateUpdate
	{
	public:
		/*
		* Initializes a new instance of the RTXInitializationStateUpdate class.
		* @param RTXInitializationState
		*/
		RTXInitializationStateUpdate(RTXInitializationState state);

		/*
		* Gets the state.
		* @return RTXInitializationState
		*/
		RTXInitializationState getState() const;
	private:
		RTXInitializationState _state;
	};
}
#endif