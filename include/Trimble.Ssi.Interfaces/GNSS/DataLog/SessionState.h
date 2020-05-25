#ifndef SESSIONSTATE_H_
#define SESSIONSTATE_H_

namespace SSI
{
	/**
	* Represents logging session states.
	*/
	enum SessionState
	{
		/**
		* Session is in undefined/disabled state.
		*/
		SessionState_Undefined=0,
		/**
		* Session is in waiting state.
		*/
		SessionState_Waiting=1,

		/**
		* Session is in active state.
		*/
		SessionState_Active=2,

		/**
		* Session is in ready state.
		*/
		SessionState_Ready=3
	};
}
#endif