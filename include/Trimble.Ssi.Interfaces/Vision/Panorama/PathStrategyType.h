#ifndef PATHSTRATEGYTYPE_H_
#define PATHSTRATEGYTYPE_H_

namespace SSI
{
	/**
	* This type implements <see cref="IPathStrategyType"/>.
	* It provides access to the basic path strategy types.
	*/
	enum PathStrategyType
	{
		PST_Speed,	/**< Represents a panorama optimized for speed. */
		PST_Quality /**< Represents a panorama optimized for quality. */
	};
}
#endif