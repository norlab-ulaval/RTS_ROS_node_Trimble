#ifndef IMUALIGNMENTSTATUS_H_
#define IMUALIGNMENTSTATUS_H_

namespace SSI
{
	enum IMUAlignmentStatus
	{
		IMUAS_Unitialized=0,
		IMUAS_CoarseLeveling,
		IMUAS_DegradedSolution,
		IMUAS_Aligned,
		IMUAS_FullNavigationMode
	};
}
#endif