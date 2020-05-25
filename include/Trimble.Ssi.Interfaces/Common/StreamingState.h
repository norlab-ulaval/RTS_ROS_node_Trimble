#ifndef STREAMINGSTATE_H_
#define STREAMINGSTATE_H_

namespace SSI
{
	/**
	* shows available streaming states.
	*/
	enum StreamingState
	{
		SS_Starting,	/**< Streaming state is Starting. */
		SS_Streaming,	/**< Streaming state is Streaming. */
		SS_Stopping,	/**< Streaming state is Stopping. */
		SS_NotStreaming /**< Streaming state is NotStreaming. */
	};
}
#endif