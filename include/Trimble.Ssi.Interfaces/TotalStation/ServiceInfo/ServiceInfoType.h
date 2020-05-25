#ifndef SERVICEINFOTYPE_H_
#define SERVICEINFOTYPE_H_

namespace SSI
{
	/**
	*   all possible service info types
	*/
	enum ServiceInfoType
	{
		SIT_NextServiceDate,		/** next sevice date */
		SIT_RuntimeInfo,			/** runtime info */
		SIT_RuntimeLeftInfo,		/** runtime left info*/
		SIT_ServiceRequiredInfo,	/** required info */
		SIT_LaserNeedsService,		/** Green high power laser required info */
		SIT_LaserLowPowerRuntime,	/** Green high laser low power runtime */
		SIT_LaserHighPowerRuntime	/** Green high laser high power runtime */
	};
}
#endif